// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AMagnetico.h"
#include "AMagneticoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SFLAB03_API UAMagneticoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAMagneticoComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    
	UPROPERTY()
		TArray<AAMagnetico* > AMagneticoActor;
	UFUNCTION()
		int32 AddToInventory(AAMagnetico* ActorToAdd);
	UFUNCTION()
		void RemoveFromInventory(AAMagnetico* ActorToRemove);
};
