// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "InputManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "ActorUtils.h"
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

	InitMesh();
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

void APlayerCharacter::Steer(const FInputActionValue& Value)
{
	float SteerValue = Value.Get<float>();

	if (SteerValue > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Steer left"));
		bSteerLeft = true;
		bSteerRight = false;
	}
	else if (SteerValue < 0)
	{
		bSteerRight = true;
		bSteerLeft = false;
		UE_LOG(LogTemp, Warning, TEXT("Steer right"));
	}
	else
	{
		bSteerRight = false;
		bSteerLeft = false;
	}
}

void APlayerCharacter::InitMesh(void)
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(MeshComponentName);

	if (MeshComponent)
	{
		MeshComponent->SetupAttachment(RootComponent);

		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*MeshPath);
		if (StaticMesh) MeshComponent->SetStaticMesh(StaticMesh);
	}
}

void APlayerCharacter::InitCamera(void)
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	if (SpringArm && MeshComponent)
	{
		SpringArm->SetupAttachment(MeshComponent);
		SpringArm->TargetArmLength = 600.0f;
		SpringArm->bUsePawnControlRotation = true;

		CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

		if (CameraComponent)
		{
			CameraComponent->SetupAttachment(SpringArm);
			CameraComponent->bUsePawnControlRotation = false;
			CameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 300.0f));
		}
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bAccelerating)
	{
		UE_LOG(LogTemp, Warning, TEXT("Accelerating"));
		CurrentSpeed = FMath::Min(CurrentSpeed + AccelerationRate * DeltaTime, MaxSpeed);
	}
	else
	{
		CurrentSpeed = FMath::Max(CurrentSpeed - BrakeRate * DeltaTime, 0.0f);
	}

	FVector ForwardVector = GetActorForwardVector();
	AddMovementInput(ForwardVector, CurrentSpeed / MaxSpeed);



	//UE_LOG(LogTemp, Warning, TEXT("Current Speed: %f"), CurrentSpeed);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!InputManager) return;

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InputManager->GetAccelerateAction(), ETriggerEvent::Triggered, this, &APlayerCharacter::Accelerate);
		EnhancedInputComponent->BindAction(InputManager->GetSteerAction(), ETriggerEvent::Triggered, this, &APlayerCharacter::Steer);
	}
}

