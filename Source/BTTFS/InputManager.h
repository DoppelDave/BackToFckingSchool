// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputManager.generated.h"

/**
 * 
 */
UCLASS()
class BTTFS_API AInputManager : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AInputManager();

private:

	void InitInputMapping(void);
	void FindActions(void);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	const class UInputAction* GetAccelerateAction(void) { return AccelerateAction; }
	const class UInputAction* GetSteerAction(void) { return SteerAction; }
	const class UInputAction* GetShootAction(void) { return ShootAction; }
	//void SetMouseCursor(bool a_bShowCursor, bool a_bClickEvents, bool a_bOverEvents);

private:

	const FString MappingContextPath = TEXT("/Game/BTTFS/Input/IMC_PlayerInput.IMC_PlayerInput");

	const FString AccelerateActionPath = TEXT("/Game/BTTFS/Input/IA_Accelerate.IA_Accelerate");
	const FString SteerActionPath = TEXT("/Game/BTTFS/Input/IA_Steer.IA_Steer");
	const FString ShootActionPath = TEXT("/Game/BTTFS/Input/IA_Shoot.IA_Shoot");

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "InputMappingContext", Category = "Input"))
	TSoftObjectPtr<class UInputMappingContext> InputMapping = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "AccelerateAction", Category = "Input"))
	class UInputAction* AccelerateAction = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "SteerAction", Category = "Input"))
	class UInputAction* SteerAction = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "ShootAction", Category = "Input"))
	class UInputAction* ShootAction = nullptr;

};
