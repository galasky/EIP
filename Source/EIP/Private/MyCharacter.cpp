

#include "EIP.h"
#include "MyCharacter.h"
#include "Engine.h"

AMyCharacter::AMyCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	this->SetActorRotation(FRotator(45, 0, 0));
	debug("Create");
}

void
AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	debug("Tick");
}

void
AMyCharacter::debug(FString msg)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, msg);
	}
}