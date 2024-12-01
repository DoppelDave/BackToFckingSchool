// Fill out your copyright notice in the Description page of Project Settings.


#include "SchoolGroundHUD.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"


ASchoolGroundHUD::ASchoolGroundHUD()
{
	UE_LOG(LogTemp, Warning, TEXT("HUD initialized"));
}

void ASchoolGroundHUD::UpdateEnemiesLeft(void)
{
	EnemiesLeft -= 1;
	FString EnemiesLeftString = FString::FromInt(static_cast<int8>(EnemiesLeft));

	if(EnemiesLeftTextBlock) EnemiesLeftTextBlock->SetText(FText::FromString(*EnemiesLeftString));

	if (EnemiesLeft == 0) EndGame();

}

void ASchoolGroundHUD::EndGame(void)
{
	PlayWinSound();
	if (UserWidgetInstance) UserWidgetInstance->RemoveFromParent();
	UserWidgetInstance = nullptr;
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	// Hole den PlayerController
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	// Wenn der Mauszeiger sichtbar war, stelle sicher, dass er ausgeblendet wird
	if (PlayerController)
	{
		PlayerController->SetShowMouseCursor(true);  // Mauszeiger ausblenden
		PlayerController->bEnableMouseOverEvents = true;  // Mausereignisse deaktivieren
		PlayerController->bEnableClickEvents = true;     // Mausklick-Ereignisse deaktivieren
	}


	UClass* WidgetClass = StaticLoadClass(UUserWidget::StaticClass(), nullptr, *EndWidgetPath);

	if (WidgetClass) EndWidgetClass = TSubclassOf<UUserWidget>(WidgetClass);

	if (EndWidgetClass)
	{
		if (!GetWorld()) return;

		
		if (PlayerController)
		{
			EndWidgetInstance = CreateWidget<UUserWidget>(PlayerController, EndWidgetClass);
			if (EndWidgetInstance)
			{
				EndWidgetInstance->AddToViewport();
			}
		}
	}
	else UE_LOG(LogTemp, Warning, TEXT("UserWidget dont have userwidgetclass"));
}

void ASchoolGroundHUD::BeginPlay()
{
	Super::BeginPlay();

	CreateUserWidget();
}

void ASchoolGroundHUD::InitTextBlock(void)
{
	EnemiesLeftTextBlock = Cast<UTextBlock>(UserWidgetInstance->GetWidgetFromName("EnemyCounter"));
}

void ASchoolGroundHUD::PlayWinSound(void)
{
	WinSoundCue = LoadObject<USoundCue>(nullptr, *WinSoundCuePath);
	if (WinSoundCue) UGameplayStatics::PlaySound2D(this, WinSoundCue);
}

void ASchoolGroundHUD::CreateUserWidget(void)
{
	UClass* WidgetClass = StaticLoadClass(UUserWidget::StaticClass(), nullptr, *WidgetPath);

	if (WidgetClass) UserWidgetClass = TSubclassOf<UUserWidget>(WidgetClass);

	if (UserWidgetClass)
	{
		if (!GetWorld()) return;

		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			UserWidgetInstance = CreateWidget<UUserWidget>(PlayerController, UserWidgetClass);
			if (UserWidgetInstance)
			{
				UserWidgetInstance->AddToViewport();
				InitTextBlock();
			}
		}
	} else UE_LOG(LogTemp, Warning, TEXT("UserWidget dont have userwidgetclass"));
}

void ASchoolGroundHUD::CreateEndWidget(void)
{
}
