// Fill out your copyright notice in the Description page of Project Settings.

#include "AA_Tube.h"
#include "AA_SpawnerComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AAA_Tube::AAA_Tube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TubeMesh"));
	RootComponent = TubeMesh;

	AttachPoint = CreateDefaultSubobject<USphereComponent>(TEXT("AttachPoint"));
	AttachPoint->SetupAttachment(RootComponent);
	AttachPoint->InitSphereRadius(10.f);

	StartTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("StartTrigger"));
	StartTrigger->SetupAttachment(RootComponent);
	StartTrigger->InitBoxExtent(FVector(500.f,4500.f,4500.f));

	EndTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("EndTrigger"));
	EndTrigger->SetupAttachment(RootComponent);
	EndTrigger->InitBoxExtent(FVector(500.f,4500.f,4500.f));

	Spawner1 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner1"));
	Spawner1->SetupAttachment(RootComponent);
	Spawners.Add(Spawner1);

	Spawner2 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner2"));
	Spawner2->SetupAttachment(RootComponent);
	Spawners.Add(Spawner2);

	Spawner3 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner3"));
	Spawner3->SetupAttachment(RootComponent);
	Spawners.Add(Spawner3);

	Spawner4 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner4"));
	Spawner4->SetupAttachment(RootComponent);
	Spawners.Add(Spawner4);

	Spawner5 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner5"));
	Spawner5->SetupAttachment(RootComponent);
	Spawners.Add(Spawner5);

	Spawner6 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner6"));
	Spawner6->SetupAttachment(RootComponent);
	Spawners.Add(Spawner6);

	Spawner7 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner7"));
	Spawner7->SetupAttachment(RootComponent);
	Spawners.Add(Spawner7);

	Spawner8 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner8"));
	Spawner8->SetupAttachment(RootComponent);
	Spawners.Add(Spawner8);

	Spawner9 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner9"));
	Spawner9->SetupAttachment(RootComponent);
	Spawners.Add(Spawner9);

	Spawner10 = CreateDefaultSubobject<UAA_SpawnerComponent>(TEXT("Spawner10"));
	Spawner10->SetupAttachment(RootComponent);
	Spawners.Add(Spawner10);
    
}

// Called when the game starts or when spawned
void AAA_Tube::BeginPlay()
{
	Super::BeginPlay();
	
}

