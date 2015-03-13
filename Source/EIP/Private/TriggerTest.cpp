

#include "EIP.h"
#include "TriggerTest.h"
#include "Engine.h"
#include <string>

ATriggerTest::ATriggerTest(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	_box = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("Box"));
	_light = PCIP.CreateDefaultSubobject<UPointLightComponent>(this, TEXT("Light"));
	_box->bGenerateOverlapEvents = true;
	_box->SetRelativeScale3D(FVector(2, 2, 5));
	RootComponent = _box;
	_light->Intensity = 10000;
	_light->AttachParent = RootComponent;
	
	_box->OnComponentBeginOverlap.AddDynamic(this, &ATriggerTest::triggerEnter);
	_box->OnComponentEndOverlap.AddDynamic(this, &ATriggerTest::triggerExit);
}

void
ATriggerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	debug("Tick");
}

void
ATriggerTest::triggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	APlayerStart *player = (APlayerStart*) OtherActor;


	auto test = OtherActor->GetUniqueID();
	FString msg;
	msg.AppendInt(test);
	debug(msg);
	_light->SetLightColor(FColor::Green);
	debug(player->GetName());
}

void
ATriggerTest::triggerExit(class AActor *otherActor, class UPrimitiveComponent *otherComponent, int32 otherBodyIndex)
{
	_light->SetLightColor(FColor::Red);
	debug("TriggerExit");
}

void
ATriggerTest::debug(FString msg)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, msg);
	}
}
