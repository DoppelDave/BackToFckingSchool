// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelGameModeBase.h"
#include "InputManager.h"
#include "PlayerCharacter.h"
#include "SchoolGroundHUD.h"


ALevelGameModeBase::ALevelGameModeBase()
{
	PlayerControllerClass = AInputManager::StaticClass();
	DefaultPawnClass = APlayerCharacter::StaticClass();
	HUDClass = ASchoolGroundHUD::StaticClass();
}