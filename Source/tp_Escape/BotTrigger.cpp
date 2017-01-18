// Fill out your copyright notice in the Description page of Project Settings.

#include "tp_Escape.h"
#include "BotTrigger.h"

#define OUT

// Sets default values for this component's properties
UBotTrigger::UBotTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = -90;
	

	// ...
}


// Called when the game starts
void UBotTrigger::BeginPlay()
{
	Super::BeginPlay();

	if (!Owner) {
		Owner = GetOwner();
	}
	else {
		return;
	}

	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	// ...
	
}


// Called every frame
void UBotTrigger::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (PressurePlate1->IsOverlappingActor(ActorThatOpen)) {
		if (!But1 && Order.Len()<3) {
			Order = Order + '1';

		}
		But1 = true;
	}
	if (PressurePlate2->IsOverlappingActor(ActorThatOpen)) {
		if (!But2 && Order.Len()<3) {
			Order = Order + '2';

		}
		But2 = true;
	}
	if (PressurePlate3->IsOverlappingActor(ActorThatOpen)) {
		if (!But3 && Order.Len()<3) {
			Order = Order + '3';

		}
		But3 = true;
	}
	if (Order.Len() == 3) {
		if (Order == "312") {
			isOpenDoor = true;
		}
		else {
			But1 = false;
			But2 = false;
			But3 = false;
			Order = "";
		}
	}

	if (isOpenDoor==true) {
		OpenDoor();
	}
	
	// ...
}

void UBotTrigger::OpenDoor()
{


	//Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	OnOpenRequest.Broadcast();

}

