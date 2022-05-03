// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "EnemigoAereo3.generated.h"

/**
 * 
 */
UCLASS()
class SFLAB03_API AEnemigoAereo3 : public ANaveAerea
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaSeconds) override;
};
