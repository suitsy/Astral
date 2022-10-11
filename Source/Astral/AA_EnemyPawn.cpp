// Fill out your copyright notice in the Description page of Project Settings.


#include "AA_EnemyPawn.h"

// Sets default values
AAA_EnemyPawn::AAA_EnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Anchor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Anchor"));
	RootComponent = Anchor;
	Anchor->SetVisibility(false);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Anchor);
}

// Called when the game starts or when spawned
void AAA_EnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAA_EnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAA_EnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

