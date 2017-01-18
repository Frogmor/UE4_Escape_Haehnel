// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "LastDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_ESCAPE_API ULastDoor : public UActorComponent
{
	GENERATED_BODY()

private:
	AActor *Owner = nullptr;

	UPROPERTY(EditAnywhere)
		ATriggerVolume *LastTrig = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *ActorOpen = nullptr;

	float OpenAngle;

public:	
	// Sets default values for this component's properties
	ULastDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void OpenDoor();
	
};
