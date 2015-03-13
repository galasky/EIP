

#pragma once

#include "GameFramework/Actor.h"
#include "TeleportationDestination.generated.h"

/**
 * 
 */
UCLASS()
class EIP_API ATeleportationDestination : public AActor
{
	GENERATED_UCLASS_BODY()

	TSubobjectPtr<UPointLightComponent>	_light;
	
	
};
