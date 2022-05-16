// Copyright Epic Games, Inc. All Rights Reserved.


#include "SFLab03GameModeBase.h"
#include "NaveAereaJugador.h"
#include "AMagnetico.h"

ASFLab03GameModeBase::ASFLab03GameModeBase()
{
}

void ASFLab03GameModeBase::SpawnMyActor()
{
	FTransform SpawnLocation;
	SpawnedActor = GetWorld()->SpawnActor<AAMagnetico>(FVector(-700.0f, 250.0f, 100.0f), FRotator::ZeroRotator);
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &ASFLab03GameModeBase::DestroyActorFunction, 5);
}

void ASFLab03GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SpawnMyActor();
	
}

void ASFLab03GameModeBase::DestroyActorFunction()
{
	if (SpawnedActor) {
		SpawnedActor->Destroy();
	}
}
