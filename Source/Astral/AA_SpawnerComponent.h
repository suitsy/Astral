// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AA_SpawnerComponent.generated.h"

class USphereComponent;

UENUM(BlueprintType)
enum ESpawnType { Enemy, Obstacle };

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRAL_API UAA_SpawnerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAA_SpawnerComponent();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	UStaticMeshComponent* Spawner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TEnumAsByte<ESpawnType>> AllowedTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsUsed = false;		
};
