// Fill out your copyright notice in the Description page of Project Settings.

#include "AA_PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAA_PlayerPawn::AAA_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerAnchor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Anchor"));
	RootComponent = PlayerAnchor;
	PlayerAnchor->SetSimulatePhysics(false);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetSimulatePhysics(false);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(Mesh);
	SpringArmComponent->TargetArmLength = 500.0f;
	SpringArmComponent->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritYaw = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bEnableCameraLag = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	ForwardForce = 2000;
	MaxVelocity = 500;
	SidewaysForce = 0.001;
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
	PlayerAnchor->SetSimulatePhysics(true);
}

void AAA_PlayerPawn::MoveRight(float AxisValue)
{
	if(bLevelAttemptStarted)
	{
		if(AxisValue != 0.f)
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveDown: %f"), AxisValue);
			//PlayerAnchor->AddImpulse(FVector(0.f, (SidewaysForce * Mesh->GetMass())* DeltaSeconds * AxisValue, 0.f), NAME_None, true);
			FVector CurrentOffset = Mesh->GetRelativeLocation();
			Mesh->SetRelativeLocation(CurrentOffset + FVector(0.f,SidewaysForce * AxisValue * DeltaSeconds,0.f) );
		}
	}

	
}

void AAA_PlayerPawn::MoveUp(float AxisValue)
{
	if(bLevelAttemptStarted)
	{
		if(AxisValue != 0.f)
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveUp: %f"), AxisValue);
			//PlayerAnchor->AddImpulse(FVector(0.f, 0.f, (SidewaysForce * Mesh->GetMass())* DeltaSeconds * AxisValue), NAME_None, true);
			FVector CurrentOffset = Mesh->GetRelativeLocation();
			Mesh->SetRelativeLocation(CurrentOffset + FVector(0.f,0.f,SidewaysForce * AxisValue * DeltaSeconds) );
		}
	}
}

void AAA_PlayerPawn::Roll(float AxisValue)
{
	if(bLevelAttemptStarted)
	{
		if(AxisValue != 0.f)
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveUp: %f"), AxisValue);
			//PlayerAnchor->AddImpulse(FVector(0.f, 0.f, (SidewaysForce * Mesh->GetMass())* DeltaSeconds * AxisValue), NAME_None, true);
			FRotator CurrentRotation = Mesh->GetRelativeRotation();
			Mesh->SetRelativeRotation(CurrentRotation + FRotator(SidewaysForce * AxisValue * DeltaSeconds,0.f,0.f) );
		}
	}
}

// Called every frame
void AAA_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DeltaSeconds = DeltaTime;

	if(bLevelAttemptStarted)
	{
		FVector Forward = PlayerAnchor->GetForwardVector();
		FVector Velocity = Forward * (ForwardForce * PlayerAnchor->GetMass()) * DeltaTime;
		PlayerAnchor->AddImpulse(Velocity, NAME_None, false);
		if(Velocity.Size() > MaxVelocity)
		{
			PlayerAnchor->SetPhysicsLinearVelocity(Velocity * MaxVelocity/Velocity.Size());
		}		
	}
}

// Called to bind functionality to input
void AAA_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &AAA_PlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &AAA_PlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis("Roll", this, &AAA_PlayerPawn::Roll);
	PlayerInputComponent->BindAxis("MouseX", this, &AAA_PlayerPawn::MouseX);
	PlayerInputComponent->BindAxis("MouseY", this, &AAA_PlayerPawn::MouseY);
}

