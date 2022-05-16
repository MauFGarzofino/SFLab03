// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveAereaJugador.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"


const FName ANaveAereaJugador::MoveForwardBinding("MoveForward");
const FName ANaveAereaJugador::MoveRigthBinding("MoveRigth");

ANaveAereaJugador::ANaveAereaJugador()
{
	// CÁMARA - MOVIMIENTO

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1800.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
	//create a camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;

	// Movement
	MoveSpeed = 200.0f;

	//Inventario
	AMagnetico = CreateDefaultSubobject<UAMagneticoComponent>(TEXT("AMagneticoInventory"));

	//ShipInfo
	AMagneticoInfo.Add("AM1", 0);
	AMagneticoInfo.Add("AM2", 0);
	AMagneticoInfo.Add("AM3", 0);
	AMagneticoInfo.Add("AM4", 0);
}


void ANaveAereaJugador::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AAMagnetico* AMagneticoItem = Cast<AAMagnetico>(Other);
	// Por si se choca a otro tipo de objeto
	if (AMagneticoItem != nullptr)
	{
		MoveSpeed = 0;
	}
}

void ANaveAereaJugador::ShowInventory()
{
	for (auto& Elem : AMagneticoInfo) {
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("% s = % d"), *Elem.Key, Elem.Value));
	}
}

void ANaveAereaJugador::Tick(float DeltaSeconds)
{
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RigthValue = GetInputAxisValue(MoveRigthBinding);

	const FVector MoveDirection = FVector(ForwardValue, RigthValue, 0.f).GetClampedToMaxSize(1.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}

void ANaveAereaJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRigthBinding);
	PlayerInputComponent->BindAction(TEXT("MostrarInventario"), IE_Pressed, this, &ANaveAereaJugador::ShowInventory);
}
