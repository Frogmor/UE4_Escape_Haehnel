// Fill out your copyright notice in the Description page of Project Settings.

#include "tp_Escape.h"
#include "LeverIinp.h"


// Sets default values for this component's properties
ULeverIinp::ULeverIinp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULeverIinp::BeginPlay()
{
	Super::BeginPlay();

	//FindPhysicsHandleComponent();
	SetInputComponent();
	Lever1->SetActorLocationAndRotation(BL1, BeginRotator);
	Lever2->SetActorLocationAndRotation(BL2, BeginRotator);
	Lever3->SetActorLocationAndRotation(BL3, BeginRotator);
}


// Called every frame
void ULeverIinp::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	
	// ...
}

void ULeverIinp::SetInputComponent() {

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) {
		InputComponent->BindAction("ActivateLever", IE_Pressed, this, &ULeverIinp::ActivateLever);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s missing phyics handleComponent"), *GetOwner()->GetName());
	}



}


void ULeverIinp::ActivateLever()
{
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();


	if (ActorHit) {
		if (ActorHit == Lever1) {
			if (posL1 == false) {
				Lever1->SetActorLocationAndRotation(NL1, NewRotator);
				posL1 = true;
			}else if (posL1 == true) {
				Lever1->SetActorLocationAndRotation(BL1, BeginRotator);
				posL1 = false;
			}
		}else if (ActorHit == Lever2) {
			if (posL2 == false) {
				Lever2->SetActorLocationAndRotation(NL2, NewRotator);
				posL2 = true;
			}else if (posL2 == true) {
				Lever2->SetActorLocationAndRotation(BL2, BeginRotator);
				posL2 = false;
			}
		}else if (ActorHit == Lever3) {
			if (posL3 == false) {
				Lever3->SetActorLocationAndRotation(NL3, NewRotator);
				posL3 = true;
			}else if (posL3 == true) {
				Lever3->SetActorLocationAndRotation(BL3, BeginRotator);
				posL3 = false;
			}
		}
		else if (ActorHit->GetFName() == "FinButton") {
			if (posL1 == true && posL2 == false && posL3 == true) {
				AToMove->SetActorLocation(FVector(150.0f, 1850.0f, 550.0f));
			}
			else {
				AToMove->SetActorLocation(FVector(-220.0f, RandomFloat(600, 1600), 550.0f));
			}
		}
	};

}

const FHitResult ULeverIinp::GetFirstPhysicsBodyInReach() {
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

FVector ULeverIinp::GetReachLineStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
		);
	return PlayerViewPointLocation;
}

FVector ULeverIinp::GetReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
		);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

float ULeverIinp::RandomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

