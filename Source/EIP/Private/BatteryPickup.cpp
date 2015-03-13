

#include "EIP.h"
#include "BatteryPickup.h"


ABatteryPickup::ABatteryPickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PowerLevel = 150.f;
}

void ABatteryPickup::OnPickedUp_Implementation()
{
	Super::OnPickedUp_Implementation();

	Destroy();
}


