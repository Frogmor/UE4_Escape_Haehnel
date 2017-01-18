// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "DoorForms.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_ESCAPE_API UDoorForms : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate1 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate2 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate3 = nullptr;

	AActor *Owner = nullptr;
	AActor *ActorThatOpen = nullptr;
	
	UPROPERTY(EditAnywhere)
	AActor *Ball1 = nullptr;
	UPROPERTY(EditAnywhere)
	AActor *Ball2 = nullptr;
	UPROPERTY(EditAnywhere)
	AActor *Ball3 = nullptr;

	float OpenAngle;
	bool ATrigger1 = false;
	bool ATrigger2 = false;
	bool ATrigger3 = false;

public:	
	// Sets default values for this component's properties
	UDoorForms();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();
	
};
