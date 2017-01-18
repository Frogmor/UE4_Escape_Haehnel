// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "DoorPlate.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_ESCAPE_API UDoorPlate : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate1 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate2 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate3 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate1 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate2 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Plate3 = nullptr;

	AActor *ActorThatOpen = nullptr;


public:	
	// Sets default values for this component's properties
	UDoorPlate();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
