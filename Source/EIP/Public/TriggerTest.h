

#pragma once

#include "GameFramework/Actor.h"
#include "TriggerTest.generated.h"

/**
 * 
 */
UCLASS()
class EIP_API ATriggerTest : public AActor
{
	GENERATED_UCLASS_BODY()

	TSubobjectPtr<UBoxComponent>		_box;
	TSubobjectPtr<UPointLightComponent>	_light;
	
	UFUNCTION()
		virtual void	Tick(float DeltaTime) override;
	UFUNCTION()
		void	debug(FString msg);
	UFUNCTION()
		void	triggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		void	triggerExit(class AActor *otherActor, class UPrimitiveComponent *otherComponent, int32 otherBodyIndex);
};
