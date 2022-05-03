// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAcuatica.h"
#include "EnemigoAcuatico.generated.h"

/**
 * 
 */
UCLASS()
class SFLAB03_API AEnemigoAcuatico : public ANaveAcuatica
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaSeconds) override;
};
