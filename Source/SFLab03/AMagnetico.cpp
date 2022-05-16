// Fill out your copyright notice in the Description page of Project Settings.


#include "AMagnetico.h"

AAMagnetico::AAMagnetico():Super()
{
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/EditorMeshes/EditorSphere.EditorSphere"));
	if (MeshAsset.Object != nullptr) {
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
}

void AAMagnetico::BeginPlay()
{
	Super::BeginPlay();
}

void AAMagnetico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
