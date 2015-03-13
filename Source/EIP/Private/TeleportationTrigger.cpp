

#include "EIP.h"
#include "TeleportationTrigger.h"
#include "Engine.h"

ATeleportationTrigger::ATeleportationTrigger(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	_box = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Box"));
	_box->bGenerateOverlapEvents = true;
	_box->SetRelativeScale3D(FVector(2, 2, 5));
	RootComponent = _box;

	_box->OnComponentBeginOverlap.AddDynamic(this, &ATeleportationTrigger::triggerEnter);
	_box->OnComponentEndOverlap.AddDynamic(this, &ATeleportationTrigger::triggerExit);
}

void
debug(FString msg)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, msg);
	}
}

void
ATeleportationTrigger::triggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	debug("téléportation");
	UGameplayStatics::OpenLevel(GWorld, _destination, false, ""); 
}

void
ATeleportationTrigger::triggerExit(class AActor *otherActor, class UPrimitiveComponent *otherComponent, int32 otherBodyIndex)
{

}