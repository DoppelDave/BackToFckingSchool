// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "../ActorUtils.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitMesh();
	//SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));
}

void ABulletActor::InitMesh(void)
{
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(BulletName);

	if (BulletMesh)
	{
		BulletMesh->SetupAttachment(RootComponent);
		
		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(*BulletPath);
		if (StaticMesh) BulletMesh->SetStaticMesh(StaticMesh);
	}
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));
	FlyDirection = GetActorForwardVector();
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation() + (-FlyDirection * BulletSpeed * DeltaTime);
	SetActorLocation(NewLocation - FVector(0.0f, 0.0f, +10.0));
}

