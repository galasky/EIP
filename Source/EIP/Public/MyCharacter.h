

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class EIP_API AMyCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UFUNCTION()
	virtual void	Tick(float DeltaTime) override;
	
	UFUNCTION()
	void			debug(FString msg);
};
