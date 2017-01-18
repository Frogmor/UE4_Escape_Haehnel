// Fill out your copyright notice in the Description page of Project Settings.

#include "tp_Escape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	SetInputComponent();
	// ...
	DigitCount1->GetTextRender()->SetText(FText::FromString(FString::FromInt(count1)));
	DigitCount2->GetTextRender()->SetText(FText::FromString(FString::FromInt(count2)));
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (PhysicsHandle->GrabbedComponent) {

		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}
	
	
	// ...
}

void UGrabber::Grab() {

	Handle();
	

}

void UGrabber::Release() {


	PhysicsHandle->ReleaseComponent();

}

void UGrabber::FindPhysicsHandleComponent() {


	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle) {

		//Found
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("%s missing phyics handleComponent"), *GetOwner()->GetName());
	}

}

void UGrabber::SetInputComponent() {

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s missing phyics handleComponent"), *GetOwner()->GetName());
	}



}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach() {
	FVector PlayerVector;
	FRotator PlayerRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerVector, OUT PlayerRotator);


	FVector LineTraceEnd = PlayerVector + PlayerRotator.Vector() * Reach;


	/// Setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	/// Line-trace (AKA ray-cast) out to reach distance
	FHitResult Hit;

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
		);

	/// See what what we hit
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()))
	}

	return Hit;


}

void UGrabber::Handle() {

	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	
	if (ActorHit) {
		if (ActorHit->GetFName() == "Button1") {
			if (count1 == 9) {count1 = 0;}
			else {count1++;}
			DigitCount1->GetTextRender()->SetText(FText::FromString(FString::FromInt(count1)));
		}
		else if (ActorHit->GetFName() == "Button2") {
			if (count2 == 9) { count2 = 0; }
			else { count2++; }
			DigitCount2->GetTextRender()->SetText(FText::FromString(FString::FromInt(count2)));
		}
		else {
			PhysicsHandle->GrabComponent(
				ComponentToGrab,
				NAME_None,
				ComponentToGrab->GetOwner()->GetActorLocation(),
				true
				);
		}
		if (count1 == 1 && count2 == 2) {
			DoorToOpen->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	};
	


}

FVector UGrabber::GetReachLineStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
		);
	return PlayerViewPointLocation;
}

FVector UGrabber::GetReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
		);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}
