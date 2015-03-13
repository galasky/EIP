// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "EIP.h"
#include "EIPCharacter.h"
#include "BatteryPickup.h"

AEIPCharacter::AEIPCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PowerLevel = 1000.f;
	SpeedFactor = 0.75f;
	BaseSpeed = 10.f;

	CollectionSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("CollectionSphere"));
	CollectionSphere->AttachTo(RootComponent);
	CollectionSphere->SetSphereRadius(200.f);

	// Set size for player capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	CharacterMovement->bOrientRotationToMovement = true; // Rotate character to moving direction
	CharacterMovement->RotationRate = FRotator(0.f, 640.f, 0.f);
	CharacterMovement->bConstrainToPlane = true;
	CharacterMovement->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUseControllerViewRotation = false; // Camera does not rotate relative to arm

}

/*void AEIPCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// Set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("CollectPickups", IE_Pressed, this, &AEIPCharacter::CollectBatteries);


}*/

void AEIPCharacter::CollectBatteries()
{
	float BatteryPower = 0.f;

	TArray<AActor*> CollectedActors;
	CollectionSphere->GetOverlappingActors(CollectedActors);

	for (int32 i = 0; i < CollectedActors.Num(); i++)
	{
		ABatteryPickup* const TestBattery = Cast<ABatteryPickup>(CollectedActors[i]);
	
		if (TestBattery && !TestBattery->IsPendingKill() && TestBattery->bIsActive)
		{
			BatteryPower = BatteryPower + TestBattery->PowerLevel;
			TestBattery->OnPickedUp();
			TestBattery->bIsActive = false;
		}
	}

	if (BatteryPower > 0.f)
	{
		PowerUp(BatteryPower);
	}
}

void AEIPCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CharacterMovement->MaxWalkSpeed = SpeedFactor * PowerLevel + BaseSpeed;
}