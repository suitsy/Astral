// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "AA_Tube.generated.h"

class UAA_SpawnerComponent;
class UBoxComponent;

UCLASS()
class ASTRAL_API AAA_Tube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAA_Tube();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* TubeMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	USphereComponent* AttachPoint;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UBoxComponent* EndTrigger;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UBoxComponent* StartTrigger;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner2;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner3;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner4;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner5;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner6;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner7;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner8;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner9;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAA_SpawnerComponent* Spawner10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Settings")
	TArray<UAA_SpawnerComponent*> Spawners;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector LastSplinePoint;
};
