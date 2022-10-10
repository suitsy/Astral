// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AA_PlayerPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
UCLASS()
class ASTRAL_API AAA_PlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAA_PlayerPawn();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	UFUNCTION()
	void MoveRight(float AxisValue);

	UFUNCTION()
	void MoveUp(float AxisValue);

	UFUNCTION()
	void Roll(float AxisValue);	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Player;	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlayerAnchor;	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ForwardForce;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SidewaysForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float DeltaSeconds;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool bLevelAttemptStarted;

private:

	bool bMoveRight;
	bool bMoveLeft;
	bool bMoveUp;
	bool bMoveDown;

	FRotator NewRotation;
};
