// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SchoolGroundHUD.generated.h"

/**
 * 
 */
UCLASS()
class BTTFS_API ASchoolGroundHUD : public AHUD
{
	GENERATED_BODY()


public:

	ASchoolGroundHUD();

	void UpdateEnemiesLeft(void);
	void EndGame(void);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void InitTextBlock(void);
	void PlayWinSound(void);

	int EnemiesLeft = 10;

	const FName WinSoundName = "WinSound";
	const FString WidgetPath = TEXT("/Game/BTTFS/Blueprints/BP_GameWidget.BP_GameWidget_C");
	const FString EndWidgetPath = TEXT("/Game/BTTFS/Blueprints/BP_EndScreen.BP_EndScreen_C");
	const FString WinSoundCuePath = TEXT("/Game/BTTFS/Audio/PLYR_Voices/Bayern/PLYR_Voice_BYR_Vic/PLYR_Voice_Vic_Cue");
	void CreateUserWidget(void);
	void CreateEndWidget(void);

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> UserWidgetClass;

	class UUserWidget* UserWidgetInstance = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> EndWidgetClass;

	class UUserWidget* EndWidgetInstance = nullptr;
	
	class UTextBlock* EnemiesLeftTextBlock = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	TObjectPtr<class USoundCue> WinSoundCue = nullptr;
};
