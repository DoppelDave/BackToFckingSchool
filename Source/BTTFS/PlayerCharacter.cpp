// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "InputManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "ActorUtils.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "BulletActor.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter initialized"));


	if (!InputManager && GetWorld()) InputManager = Cast<AInputManager>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (InputManager) UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter initialized InputManager"));

	InitSoundCues();
	InitMeshComponents();
	InitCamera();
}

void APlayerCharacter::RotateCamera(void)
{
	if (!SpringArm || !InputManager) return;

	float MouseX, MouseY;

	InputManager->GetInputMouseDelta(MouseX, MouseY);

	FRotator CurrentRotation = SpringArm->GetRelativeRotation();
	FRotator CurrentRotationGun = CurrentRotation;
	CurrentRotationGun.Yaw -= MouseX + 180.0f;
	CurrentRotation.Yaw += MouseX;
	SpringArm->SetRelativeRotation(CurrentRotation);

	
	if (!GunMesh) return;
	GunMesh->SetRelativeRotation(CurrentRotationGun);
}

void APlayerCharacter::Accelerate(const FInputActionValue& Value)
{
	float AccelerationValue = Value.Get<float>();

	if (AccelerationValue > 0)
	{
		bAccelerating = true;
	}
	else if (AccelerationValue < 0)
	{
		bAccelerating = false;
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

	float YawInput = SpeedFactor * SteerValue * SteeringSpeed;

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

		GunMesh->SetRelativeScale3D(FVector(0.7f, 0.7f, 0.7f));
		GunMesh->SetRelativeLocation(FVector(-25.0f, 25.0f, 90.0f));
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
		SpringArm->bUsePawnControlRotation = false;
		SpringArm->bDoCollisionTest = false;

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
		CollisionBox->SetHiddenInGame(true);

		BaseMesh->SetWorldRotation(StartRotation);

		BaseMesh->SetRelativeLocation(FVector(0.0f, 25.0f, -40.0f));
	}
	SetActorScale3D(StartScale);
}

void APlayerCharacter::InitSoundCues(void)
{
	AccelerationSoundCue = FindObject<USoundCue>(*AccelerationSoundPath);
	IdleSoundCue = FindObject<USoundCue>(*IdleSoundPath);
	SlowDownSoundCue = FindObject<USoundCue>(*SlowDownSoundPath);
	MaxSpeedSoundCue = FindObject<USoundCue>(*MaxSpeedSoundPath);
}

void APlayerCharacter::PlaySoundCue(USoundCue* a_SoundCue)
{
	if (a_SoundCue) UGameplayStatics::PlaySound2D(this, a_SoundCue);
}

void APlayerCharacter::Shoot(void)
{
	UE_LOG(LogTemp, Warning, TEXT("Shoot"));

	if (!GetWorld()) return;

	FVector SpawnLocation = GetActorLocation() + FVector(0.0f, 0.0f, 150.0f);
	FRotator SpawnRotation = GunMesh->GetComponentRotation();
	GetWorld()->SpawnActor<ABulletActor>(SpawnLocation, SpawnRotation);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitTransform();
	GetCharacterMovement()->MaxWalkSpeed = MaxSpeed;
	//PlaySoundCue(IdleSoundCue);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateCamera();

	if (bAccelerating)
	{
		//if (AccelerationSoundCue)
		//{
		//	if (AudioComponentInstance && !AudioComponentInstance->IsPlaying()) return;
		//	// Sound an einen Actor oder eine Komponente anhängen
		//	AudioComponentInstance = UGameplayStatics::SpawnSoundAttached(
		//		AccelerationSoundCue,
		//		this->GetRootComponent(), // An den Root-Component anhängen
		//		NAME_None,               // Keine spezielle Socket
		//		FVector::ZeroVector,     // Position (relativ zum Root)
		//		FRotator::ZeroRotator,   // Rotation
		//		EAttachLocation::KeepRelativeOffset,
		//		true                     // Loopen des Sounds
		//	);
		//}

		//PlaySoundCue(AccelerationSoundCue);
		float DeltaSpeed = FMath::Square((MaxSpeed - CurrentSpeed) / MaxSpeed) * AccelerationRate * DeltaTime;
		CurrentSpeed = FMath::Clamp(CurrentSpeed + DeltaSpeed, 0.0f, MaxSpeed);
	}
	else
	{
		CurrentSpeed = FMath::Max(CurrentSpeed - BrakeRate * DeltaTime, 0.0f);
	}

	FVector ForwardVector = GetActorForwardVector();
	AddMovementInput(ForwardVector, CurrentSpeed / MaxSpeed);
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

		EnhancedInputComponent->BindAction(InputManager->GetShootAction(), ETriggerEvent::Triggered, this, &APlayerCharacter::Shoot);
	}
}

