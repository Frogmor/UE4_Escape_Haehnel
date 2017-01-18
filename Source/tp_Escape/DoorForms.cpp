// Fill out your copyright notice in the Description page of Project Settings.

#include "tp_Escape.h"
#include "DoorForms.h"


// Sets default values for this component's properties
UDoorForms::UDoorForms()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = -90;
	// ...
}


// Called when the game starts
void UDoorForms::BeginPlay()
{
	Super::BeginPlay();

	if (!Owner) {
		Owner = GetOwner();
	}
	else {
		return;
	}
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


// Called every frame
void UDoorForms::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (PressurePlate1->IsOverlappingActor(Ball1) ) {
		ATrigger1 = true;
	}
	if (PressurePlate2->IsOverlappingActor(Ball2)) {
		ATrigger2 = true;
	}
	if (PressurePlate3->IsOverlappingActor(Ball3)) {
		ATrigger3 = true;
	}

	if (ATrigger1 && ATrigger2 && ATrigger3) {
		OpenDoor();
	}
}
void UDoorForms::OpenDoor()
{


	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	//OnOpenRequest.Broadcast();
}


