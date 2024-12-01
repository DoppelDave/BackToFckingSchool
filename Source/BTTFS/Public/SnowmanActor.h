// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnowmanActor.generated.h"

UCLASS()
class BTTFS_API ASnowmanActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnowmanActor();

private:

	void InitComponents(void);
	void InitMesh(void);
	void InitCollisionBox(void);
	void InitTransform(void);
	void PlayHitEffect(void);
	void UpdateEnemiesLeft(void);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	const FString MeshPath = TEXT("/Game/BTTFS/Art/SnowMan/Schneeman_Schneeman");
	const FString HelmetPath = TEXT("/Game/BTTFS/Art/SnowMan/Schneeman_Helm");
	const FString TiePath = TEXT("/Game/BTTFS/Art/SnowMan/Schneeman_Krawatte");
	const FString BowTiePath = TEXT("/Game/BTTFS/Art/SnowMan/Schneeman_Fliege");
	const FString HatPath = TEXT("/Game/BTTFS/Art/SnowMan/Schneeman_Hut");
	const FString HitEffectPath = TEXT("/Script/Niagara.NiagaraSystem'/Game/BTTFS/Effects/P_Schneeman_Explosion.P_Schneeman_Explosion'");
	
	const FName MeshName = "BaseMesh";
	const FName DecorationName = "Decoration";
	const FName CollisionBoxName = "CollisionBox";
	const FName NiagaraName = "Effect";

	FVector CollisionBoxSize = FVector(40.0f, 40.0f, 70.0f);
	FVector Size = FVector(3.0f, 3.0f, 3.0f);

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "BaseMesh", Category = "Components"))
	TObjectPtr<UStaticMeshComponent> BaseMesh = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "Decoration", Category = "Components"))
	TObjectPtr<UStaticMeshComponent> Decoration = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "CollisionBox", Category = "Components"))
	TObjectPtr<class UBoxComponent> CollisionBox = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "Niagara", Category = "Components"))
	TObjectPtr<class UNiagaraComponent> NiagaraComponent = nullptr;

	UPROPERTY(EditAnywhere,
		meta = (DisplayName = "HitEffect", Category = "Effects"))
	TObjectPtr<class UNiagaraSystem> HitEffect = nullptr;
};
