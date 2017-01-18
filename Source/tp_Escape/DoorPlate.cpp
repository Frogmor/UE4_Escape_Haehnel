// Fill out your copyright notice in the Description page of Project Settings.

#include "tp_Escape.h"
#include "DoorPlate.h"


// Sets default values for this component's properties
UDoorPlate::UDoorPlate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UDoorPlate::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UDoorPlate::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (PressurePlate1->IsOverlappingActor(ActorThatOpen)) {
		Plate1->SetActorLocation(FVector(-150.0f, -700.0f, 100.0f));
		Plate2->SetActorLocation(FVector(-150.0f, -500.0f, 100.0f));
		Plate3->SetActorLocation(FVector(-150.0f, -300.0f, 0.0f));
	}
	if (PressurePlate3->IsOverlappingActor(ActorThatOpen)) {
		Plate1->SetActorLocation(FVector(-150.0f, -700.0f, 100.0f));
		Plate2->SetActorLocation(FVector(-150.0f, -500.0f, 0.0f));
		Plate3->SetActorLocation(FVector(-150.0f, -300.0f, 100.0f));
	}
	if (PressurePlate2->IsOverlappingActor(ActorThatOpen)) {
		Plate2->SetActorLocation(FVector(-150.0f, -500.0f, 100.0f));
		Plate3->SetActorLocation(FVector(-150.0f, -300.0f, 100.0f));
	}
}

