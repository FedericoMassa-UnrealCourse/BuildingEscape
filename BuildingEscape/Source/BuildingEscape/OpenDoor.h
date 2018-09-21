// Copyright Ben Tristem 2016.

#pragma once

#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


private:

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	AActor* Owner = nullptr; // The owning door

	UPROPERTY(EditAnywhere)
	// Mass that if put on the plate triggers the door opening
	float TriggerMass = 20.f;

	float GetTotalMassOfActorsOnPlate() const;

	// Delegate to open door
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	// Delegate to close door
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;
};
