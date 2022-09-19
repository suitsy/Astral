// Fill out your copyright notice in the Description page of Project Settings.


#include "AA_Tube.h"

// Sets default values
AAA_Tube::AAA_Tube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TubeMesh"));
	RootComponent = TubeMesh;

	AttachPoint = CreateDefaultSubobject<USphereComponent>(TEXT("AttachPoint"));
	AttachPoint->SetupAttachment(RootComponent);
	AttachPoint->InitSphereRadius(10.f);
}

// Called when the game starts or when spawned
void AAA_Tube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAA_Tube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

