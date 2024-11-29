// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

template <typename T>
T* FindObject(const FString a_sObjPath)
{
	return ConstructorHelpers::FObjectFinder<T>(*a_sObjPath).Object;
}
