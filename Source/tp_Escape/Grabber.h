// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Engine/TextRenderActor.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
		float Reach = 200.0f;
	int count1 = 0;
	int count2 = 0;

	UPhysicsHandleComponent *PhysicsHandle = nullptr;

	UPROPERTY(EditAnywhere)
		ATextRenderActor *DigitCount1 = nullptr;
	UPROPERTY(EditAnywhere)
		ATextRenderActor *DigitCount2 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *DoorToOpen = nullptr;


	UInputComponent *InputComponent = nullptr;

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void Grab();

	void Release();

	void FindPhysicsHandleComponent();

	void SetInputComponent();

	const FHitResult GetFirstPhysicsBodyInReach();

	void Handle();

	FVector GetReachLineStart();

	FVector GetReachLineEnd();
		
	
};
