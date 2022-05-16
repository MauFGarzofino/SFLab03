// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SFLab03GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SFLAB03_API ASFLab03GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASFLab03GameModeBase();
	UFUNCTION()
		void SpawnMyActor();
	UPROPERTY()
		class AAMagnetico * SpawnedActor;
	UFUNCTION()
		void DestroyActorFunction();

	virtual void BeginPlay() override;
};
