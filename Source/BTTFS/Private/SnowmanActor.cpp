// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowmanActor.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "SchoolGroundHUD.h"
#include "../PlayerCharacter.h"

// Sets default values
ASnowmanActor::ASnowmanActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitComponents();
}

void ASnowmanActor::InitComponents(void)
{
	InitMesh();
	InitCollisionBox();

	if (!NiagaraComponent) NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(NiagaraName);
	if (NiagaraComponent && BaseMesh) NiagaraComponent->SetupAttachment(BaseMesh);
}

void ASnowmanActor::InitMesh(void)
{
	if (!BaseMesh) BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(MeshName);
	if (BaseMesh)
	{
		UStaticMesh* StaticMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(*MeshPath).Object;
		if (StaticMesh) BaseMesh->SetStaticMesh(StaticMesh);

		if (!Decoration) Decoration = CreateDefaultSubobject<UStaticMeshComponent>(DecorationName);
		if (Decoration) Decoration->SetupAttachment(BaseMesh);
	}
}

void ASnowmanActor::InitCollisionBox(void)
{
	if (!CollisionBox) CollisionBox = CreateDefaultSubobject<UBoxComponent>(CollisionBoxName);
	if (CollisionBox)
	{
		if(BaseMesh) CollisionBox->SetupAttachment(BaseMesh);
		CollisionBox->SetBoxExtent(CollisionBoxSize);
		CollisionBox->SetHiddenInGame(true);
		CollisionBox->SetVisibility(false);
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CollisionBox->SetCollisionObjectType(ECC_WorldDynamic);
		CollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
		CollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ASnowmanActor::OnOverlapBegin);
	}
}

void ASnowmanActor::InitTransform(void)
{
	SetActorScale3D(Size);
}

void ASnowmanActor::PlayHitEffect(void)
{
	HitEffect = LoadObject<UNiagaraSystem>(nullptr, *HitEffectPath);

	if (NiagaraComponent && HitEffect)
	{
		NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), HitEffect, GetActorLocation());
		NiagaraComponent->Activate();
	}
}

void ASnowmanActor::UpdateEnemiesLeft(void)
{
	if (!GetWorld()) return;
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		ASchoolGroundHUD* SchoolGroundHUD = Cast<ASchoolGroundHUD>(PlayerController->GetHUD());
		if (SchoolGroundHUD) SchoolGroundHUD->UpdateEnemiesLeft();
		else UE_LOG(LogTemp, Warning, TEXT("Snowman has no HUD"));
	}
}

void ASnowmanActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this))
	{
		APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
		if (!PlayerCharacter) return;
		PlayHitEffect();
		UpdateEnemiesLeft();
		Destroy();

		UE_LOG(LogTemp, Warning, TEXT("Overlap Begin with: %s"), *OtherActor->GetName());
	}
}

// Called when the game starts or when spawned
void ASnowmanActor::BeginPlay()
{
	Super::BeginPlay();

	InitTransform();
}

// Called every frame
void ASnowmanActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

