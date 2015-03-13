

#include "EIP.h"
#include "TeleportationDestination.h"


ATeleportationDestination::ATeleportationDestination(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	_light = PCIP.CreateDefaultSubobject<UPointLightComponent>(this, TEXT("Light"));
	_light->Intensity = 100000;
	RootComponent = _light;
}