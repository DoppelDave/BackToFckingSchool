// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "InputManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter initialized"));


	if (!InputManager && GetWorld()) InputManager = Cast<AInputManager>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (InputManager) UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter initialized InputManager"));
}

//void APlayerCharacter::Accelerate(const FInputActionValue& Value)
//{
//	bRotate = Value.Get<bool>();
//	UE_LOG(LogTemp, Warning, TEXT("Accelerate"));
//}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!InputManager) return;

	/*if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InputManager->GetAccelerateAction(), ETriggerEvent::Triggered, this, &APlayerCharacter::Accelerate);
	}*/
}

