

#include "EIP.h"
#include "Pickup.h"


APickup::APickup(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bIsActive = true;

	BaseCollisionComponent = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("BaseSphereComponent"));

	RootComponent = BaseCollisionComponent;

	PickupMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("PickupMesh"));

	PickupMesh->SetSimulatePhysics(true);

	PickupMesh->AttachTo(RootComponent);
}


void APickup::OnPickedUp_Implementation()
{

}