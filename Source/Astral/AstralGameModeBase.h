// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AstralGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartTimer);

/**
 * 
 */
UCLASS()
class ASTRAL_API AAstralGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	AAstralGameModeBase();
};
