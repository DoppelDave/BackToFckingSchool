// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class BTTFS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

private:

	void Accelerate(const struct FInputActionValue& Value);
	void StopAccelerate(void);
	void StopSteer(void); 
	void Steer(const struct FInputActionValue& Value);
	void InitMeshComponents(void);
	void InitCamera(void);
	void InitTransform(void);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	bool bAccelerating = false;
	bool bSteerLeft = false;
	bool bSteerRight = false;

	FRotator StartRotation = FRotator(0.0f, -180.0f, 0.0f);
	FVector StartScale = FVector(2.5f, 2.5f, 2.5f);

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "MaxSpeed", Category = "Data"))
	float MaxSpeed = 4000.0f;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "AccelerationRate", Category = "Data"))
	float AccelerationRate = 3000.0f;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "BrakeRate", Category = "Data"))
	float BrakeRate = 1500.0f;

	float CurrentSpeed = 0.0f;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "MaxSteeringAngle", Category = "Data"))
	float MaxSteeringAngle = 2.0f;

		UPROPERTY(EditAnywhere,
			meta = (DisplayName = "BrakeRate", Category = "Data"))
	float SteeringSpeed = 3.0f;

	float CurrentSteeringAngle = 0.0f;
	

	const FString BaseMeshPath = TEXT("/Game/BTTFS/Art/SnowCar/SM_Base");
	const FString WheelLFPath = TEXT("/Game/BTTFS/Art/SnowCar/SM_Wheel_LF");
	const FString WheelLBPath = TEXT("/Game/BTTFS/Art/SnowCar/SM_Wheel_LB");
	const FString WheelRFPath = TEXT("/Game/BTTFS/Art/SnowCar/SM_Wheel_RF");
	const FString WheelRBPath = TEXT("/Game/BTTFS/Art/SnowCar/SM_Wheel_RB");
	const FString GunPath = TEXT("/Game/BTTFS/Art/SnowCar/SM_Gun");

	const FName BaseComponentName = TEXT("Base");
	const FName WheelLFName = TEXT("WheelLF");
	const FName WheelLBName = TEXT("WheelLB");
	const FName WheelRFName = TEXT("WheelRF");
	const FName WheelRBName = TEXT("WheelRB");
	const FName GunName = TEXT("Gun");


	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "InputManager", Category = "Manager"))
	class AInputManager* InputManager = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "Base", Category = "Components"))
	class UStaticMeshComponent* BaseMesh = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "WheelLF", Category = "Components"))
	class UStaticMeshComponent* WheelLF = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "WheelLB", Category = "Components"))
	class UStaticMeshComponent* WheelLB = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "WheelRF", Category = "Components"))
	class UStaticMeshComponent* WheelRF = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "WheelRB", Category = "Components"))
	class UStaticMeshComponent* WheelRB = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "Gun", Category = "Components"))
	class UStaticMeshComponent* GunMesh = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "SpringArm", Category = "Components"))
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "Camera", Category = "Components"))
	class UCameraComponent* CameraComponent = nullptr;

};
