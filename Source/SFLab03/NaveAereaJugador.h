// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaJugador.generated.h"

/**
 * 
 */
UCLASS()
class SFLAB03_API ANaveAereaJugador : public ANaveAerea
{
	GENERATED_BODY()

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
	/** Spring arm that will offset the camera */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

public:
	ANaveAereaJugador();

public:
	// statics names for axis Bindings

	static const FName MoveForwardBinding;
	static const FName MoveRigthBinding;
public:

virtual void Tick(float DeltaSeconds) override;
virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
FORCEINLINE class USpringArmComponent* GetSpringArm() const { return CameraBoom; }
};
