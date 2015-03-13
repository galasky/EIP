

#pragma once

#include "GameFramework/Actor.h"
#include "TeleportationDestination.h"
#include "TeleportationTrigger.generated.h"


/**
 * 
 */
UCLASS()
class EIP_API ATeleportationTrigger : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teleportation")
	FName							_destination;

	TSubobjectPtr<UBoxComponent>	_box;

	
	UFUNCTION()
		void	triggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
		void	triggerExit(class AActor *otherActor, class UPrimitiveComponent *otherComponent, int32 otherBodyIndex);
};
