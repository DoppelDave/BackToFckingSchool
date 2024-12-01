// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class BTTFS_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

private:

	void InitMesh(void);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	float BulletSpeed = 5000.0f;
	FVector FlyDirection = FVector(1.0f, 0.0f, 0.0f);

	const FName BulletName = "SnowBall";
	const FString BulletPath = TEXT("/Game/BTTFS/Art/Snowball");

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> BulletMesh = nullptr;
};
