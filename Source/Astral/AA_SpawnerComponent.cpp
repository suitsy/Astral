// Fill out your copyright notice in the Description page of Project Settings.

#include "AA_SpawnerComponent.h"

// Sets default values for this component's properties
UAA_SpawnerComponent::UAA_SpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Spawner = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spawner"));
}


// Called when the game starts
void UAA_SpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

