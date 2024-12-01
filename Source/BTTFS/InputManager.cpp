// Fill out your copyright notice in the Description page of Project Settings.


#include "InputManager.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "ActorUtils.h"

AInputManager::AInputManager()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("InputManager initialized"));

	if (!InputMapping) InputMapping = FindObject<UInputMappingContext>(*MappingContextPath);

	FindActions();

}

void AInputManager::BeginPlay()
{
	Super::BeginPlay();

	InitInputMapping();
}

void AInputManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInputManager::InitInputMapping()
{
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!InputMapping.IsNull())
			{
				InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 1);
			}
		}
	}
}


void AInputManager::FindActions()
{
	if (!AccelerateAction) AccelerateAction = FindObject<UInputAction>(*AccelerateActionPath);
	if (!SteerAction) SteerAction = FindObject<UInputAction>(*SteerActionPath);
	if (!ShootAction) ShootAction = FindObject<UInputAction>(*ShootActionPath);
	//if (!OnClickAction) OnClickAction = FindObject<UInputAction>(*OnClickActionPath);
	//if (!PauseAction) PauseAction = FindObject<UInputAction>(*PauseActionPath);*/
}
