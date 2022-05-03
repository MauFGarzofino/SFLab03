// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuatico.h"

void AEnemigoAcuatico::Tick(float DeltaSeconds)
{
	srand(time(NULL));
	float rand2 = rand() % 12 - 3;
	float rand1 = rand() % 32 - 2;
	//static float rand1 = FMath::RandRange(10, -5);
	//static float rand2 = FMath::RandRange(10, -5);
	MoveSpeed = 250.0f;

	const FVector MoveDirection = FVector(rand1, rand2, 0.0f).GetClampedToMaxSize(1.0f);

	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}
