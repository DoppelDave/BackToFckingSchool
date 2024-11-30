// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "InputManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "ActorUtils.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter initialized"));


	if (!InputManager && GetWorld()) InputManager = Cast<AInputManager>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (InputManager) UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter initialized InputManager"));

	InitMeshComponents();
	InitCamera();
}

void APlayerCharacter::Accelerate(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Should Accelerate"));

	float AccelerationValue = Value.Get<float>();

	if (AccelerationValue > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Accelerate"));
		bAccelerating = true;
	}
	else if (AccelerationValue < 0)
	{
		bAccelerating = false;
		UE_LOG(LogTemp, Warning, TEXT("Break"));
	}
	else bAccelerating = false;
}

void APlayerCharacter::StopAccelerate(void)
{
	bAccelerating = false;
}


void APlayerCharacter::StopSteer(void)
{
	bSteerLeft = false;
	bSteerRight = false;
}

void APlayerCharacter::Steer(const FInputActionValue& Value)
{
	float SteerValue = Value.Get<float>();

	float SpeedFactor = FMath::Clamp(CurrentSpeed / MaxSpeed, 0.0f, 1.0f);

	float YawInput = SpeedFactor * SteerValue;

	float ClampedYawInput = FMath::Clamp(YawInput, -MaxSteeringAngle, MaxSteeringAngle);

	AddControllerYawInput(ClampedYawInput);
}

void APlayerCharacter::InitMeshComponents(void)
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(BaseComponentName);

	if (BaseMesh)
	{
		BaseMesh->SetupAttachment(RootComponent);

		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*BaseMeshPath);
		if (StaticMesh) BaseMesh->SetStaticMesh(StaticMesh);
	}

	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(GunName);

	if (GunMesh)
	{
		GunMesh->SetupAttachment(BaseMesh);

		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*GunPath);
		if (StaticMesh) GunMesh->SetStaticMesh(StaticMesh);
	}

	WheelLB = CreateDefaultSubobject<UStaticMeshComponent>(WheelLBName);

	if (WheelLB)
	{
		WheelLB->SetupAttachment(BaseMesh);

		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*WheelLBPath);
		if (StaticMesh) WheelLB->SetStaticMesh(StaticMesh);
	}

	WheelRB = CreateDefaultSubobject<UStaticMeshComponent>(WheelRBName);

	if (WheelRB)
	{
		WheelRB->SetupAttachment(BaseMesh);

		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*WheelRBPath);
		if (StaticMesh) WheelRB->SetStaticMesh(StaticMesh);
	}

	WheelLF = CreateDefaultSubobject<UStaticMeshComponent>(WheelLFName);

	if (WheelLF)
	{
		WheelLF->SetupAttachment(BaseMesh);

		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*WheelLFPath);
		if (StaticMesh) WheelLF->SetStaticMesh(StaticMesh);
	}

	WheelRF = CreateDefaultSubobject<UStaticMeshComponent>(WheelRFName);

	if (WheelRF)
	{
		WheelRF->SetupAttachment(BaseMesh);

		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*WheelRFPath);
		if (StaticMesh) WheelRF->SetStaticMesh(StaticMesh);
	}
	
}

void APlayerCharacter::InitCamera(void)
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	if (SpringArm && BaseMesh)
	{
		SpringArm->SetupAttachment(BaseMesh);
		SpringArm->TargetArmLength = 600.0f;
		SpringArm->bUsePawnControlRotation = true;

		CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

		if (CameraComponent)
		{
			CameraComponent->SetupAttachment(SpringArm);
			CameraComponent->bUsePawnControlRotation = false;
			CameraComponent->SetRelativeLocation(FVector(40.0f, -23.0f, 180.0f));
			CameraComponent->SetRelativeRotation(FRotator(-25.0f, 0.0f, 0.0f));
			
		}
	}
}

void APlayerCharacter::InitTransform(void)
{
	if (BaseMesh)
	{
		UCapsuleComponent* CollisionBox = GetCapsuleComponent();

		CollisionBox->SetCapsuleHalfHeight(50.0f);
		CollisionBox->SetHiddenInGame(false);

		BaseMesh->SetWorldRotation(StartRotation);

		BaseMesh->SetRelativeLocation(FVector(0.0f, 25.0f, -40.0f));
	}
	SetActorScale3D(StartScale);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitTransform();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bAccelerating)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Accelerating"));
		CurrentSpeed = FMath::Min(CurrentSpeed + AccelerationRate * DeltaTime, MaxSpeed);
	}
	else
	{
		CurrentSpeed = FMath::Max(CurrentSpeed - BrakeRate * DeltaTime, 0.0f);
	}

	FVector ForwardVector = GetActorForwardVector();
	AddMovementInput(ForwardVector, CurrentSpeed / MaxSpeed);

	UE_LOG(LogTemp, Warning, TEXT("Current Speed: %f"), CurrentSpeed);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!InputManager) return;

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InputManager->GetAccelerateAction(), ETriggerEvent::Triggered, this, &APlayerCharacter::Accelerate);
		EnhancedInputComponent->BindAction(InputManager->GetAccelerateAction(), ETriggerEvent::Completed, this, &APlayerCharacter::StopAccelerate);

		EnhancedInputComponent->BindAction(InputManager->GetSteerAction(), ETriggerEvent::Triggered, this, &APlayerCharacter::Steer);
		EnhancedInputComponent->BindAction(InputManager->GetSteerAction(), ETriggerEvent::Completed, this, &APlayerCharacter::StopSteer);
	}
}

