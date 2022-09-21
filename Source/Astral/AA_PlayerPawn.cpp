// Fill out your copyright notice in the Description page of Project Settings.

#include "AA_PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AAA_PlayerPawn::AAA_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Character = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Character"));
	RootComponent = Character;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 500.0f;
	SpringArmComponent->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));
	SpringArmComponent->bInheritPitch = true;
	SpringArmComponent->bInheritYaw = true;
	SpringArmComponent->bInheritRoll = true;
	SpringArmComponent->bEnableCameraLag = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	ForwardForce = 2000;
	MaxVelocity = 500;
	SidewaysForce = 25;
	bLevelAttemptStarted = false;
	bMoveRight = false;
	bMoveLeft = false;
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AAA_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	bLevelAttemptStarted = true;
}

void AAA_PlayerPawn::MoveRight(float AxisValue)
{
	if(bLevelAttemptStarted)
	{
		if(AxisValue != 0.f)
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveDown: %f"), AxisValue);
			Character->AddImpulse(FVector(0.f, (SidewaysForce * Character->GetMass())* DeltaSeconds * AxisValue, 0.f), NAME_None, true);		
		}
	}

	bMoveRight = AxisValue > 0.f ? true : false;
	bMoveLeft = AxisValue < 0.f ? true : false;
}

void AAA_PlayerPawn::MoveUp(float AxisValue)
{
	if(bLevelAttemptStarted)
	{
		if(AxisValue != 0.f)
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveUp: %f"), AxisValue);
			Character->AddImpulse(FVector(0.f, 0.f, (SidewaysForce * Character->GetMass())* DeltaSeconds * AxisValue), NAME_None, true);		
		}
	}
	
	bMoveUp = AxisValue > 0.f ? true : false;
	bMoveDown = AxisValue < 0.f ? true : false;
}

void AAA_PlayerPawn::MouseX(float AxisValue)
{
	if(AxisValue != 0.f)
	{
		FRotator XRotation = FRotator(0.f,AxisValue * DeltaSeconds * (SidewaysForce * 4),0.f);
		Character->SetRelativeRotation(UKismetMathLibrary::ComposeRotators(Character->GetRelativeRotation(),XRotation));
	}	
}

void AAA_PlayerPawn::MouseY(float AxisValue)
{
	if(AxisValue != 0.f)
	{
		FRotator XRotation = FRotator(AxisValue * DeltaSeconds * (SidewaysForce * 4),0.f,0.f);		
		Character->SetRelativeRotation(UKismetMathLibrary::ComposeRotators(Character->GetRelativeRotation(),XRotation));
	}	
}

// Called every frame
void AAA_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DeltaSeconds = DeltaTime;

	if(bLevelAttemptStarted)
	{
		FVector Forward = Character->GetForwardVector();
		FVector Velocity = Forward * (ForwardForce * Character->GetMass()) * DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("Velocity: %s"), *Velocity.ToString());
		//Character->AddImpulse(Velocity, NAME_None, false);
		if(Velocity.Size() > MaxVelocity)
		{
			Character->SetPhysicsLinearVelocity(Velocity * MaxVelocity/Velocity.Size());
		}		
	}
}

// Called to bind functionality to input
void AAA_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &AAA_PlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &AAA_PlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis("MouseX", this, &AAA_PlayerPawn::MouseX);
	PlayerInputComponent->BindAxis("MouseY", this, &AAA_PlayerPawn::MouseY);
}

