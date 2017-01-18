// Fill out your copyright notice in the Description page of Project Settings.

#include "tp_Escape.h"
#include "LastDoor.h"


// Sets default values for this component's properties
ULastDoor::ULastDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = -45.0f;

	// ...
}


// Called when the game starts
void ULastDoor::BeginPlay()
{
	Super::BeginPlay();
	
	if (!Owner) {
		Owner = GetOwner();
	}
	else {
		return;
	}
	
}


// Called every frame
void ULastDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (LastTrig->IsOverlappingActor(ActorOpen)) {
		OpenDoor();
	}
}

void ULastDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}