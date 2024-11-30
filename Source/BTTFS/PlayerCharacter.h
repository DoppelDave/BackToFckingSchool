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
	void InitMesh(void);
	void InitCamera(void);

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
	float MaxSteeringAngle = 30.0f;

		UPROPERTY(EditAnywhere,
			meta = (DisplayName = "BrakeRate", Category = "Data"))
	float SteeringSpeed = 50.0f;

	float CurrentSteeringAngle = 0.0f;
	

	const FString MeshPath = TEXT("/Game/StarterContent/Props/SM_Couch");
	const FName MeshComponentName = TEXT("SnowCar");


	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "InputManager", Category = "Manager"))
	class AInputManager* InputManager = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "Mesh", Category = "Components"))
	class UStaticMeshComponent* MeshComponent = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "SpringArm", Category = "Components"))
	class USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "Camera", Category = "Components"))
	class UCameraComponent* CameraComponent = nullptr;

};
