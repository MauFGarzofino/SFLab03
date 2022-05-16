// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "AMagnetico.generated.h"

/**
 * 
 */
UCLASS()
class SFLAB03_API AAMagnetico : public AStaticMeshActor
{
	GENERATED_BODY()
private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Datos", meta = (AllowPrivateAccess = "true"))
		FString Name;

public: 
	AAMagnetico();

protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE FString GetNombre() const { return Name; }
	FORCEINLINE void SetNombre(const FString _Name) { Name = _Name; }
};
