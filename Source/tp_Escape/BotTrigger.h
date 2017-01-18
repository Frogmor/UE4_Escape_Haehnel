// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BotTrigger.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorevent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_ESCAPE_API UBotTrigger : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate1 = nullptr;
	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate2 = nullptr;
	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate3 = nullptr;

	
	AActor *ActorThatOpen = nullptr;

	FString Order = "";
	bool But1 = false;
	bool But2 = false;
	bool But3 = false;
	bool isOpenDoor = false;
	float OpenAngle;

	UPROPERTY(BlueprintAssignable)
		FDoorevent OnOpenRequest;

	AActor *Owner = nullptr;

public:	
	// Sets default values for this component's properties
	UBotTrigger();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();

		
	
};
