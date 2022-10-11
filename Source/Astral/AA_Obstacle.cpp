// Fill out your copyright notice in the Description page of Project Settings.


#include "AA_Obstacle.h"

// Sets default values
AAA_Obstacle::AAA_Obstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AAA_Obstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAA_Obstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

