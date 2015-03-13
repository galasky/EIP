

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class EIP_API APickup : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	bool bIsActive;

	UPROPERTY(VisibleDefaultsOnly, BluePrintReadOnly, Category = Pickup)
	TSubobjectPtr<USphereComponent> BaseCollisionComponent;
	
	UPROPERTY(VisibleDefaultsOnly, BluePrintReadOnly, Category = Pickup)
	TSubobjectPtr<UStaticMeshComponent> PickupMesh;

	UFUNCTION(BluePrintNativeEvent)
	void OnPickedUp();
};
