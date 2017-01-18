// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "LeverIinp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TP_ESCAPE_API ULeverIinp : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
		float Reach = 200.0f;
	UPROPERTY(EditAnywhere)
		AActor *Lever1 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Lever2 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *Lever3 = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *AToMove = nullptr;

	bool posL1 = false;
	bool posL2 = false;
	bool posL3 = false;

	FRotator BeginRotator = FRotator(0.0f, 0.0f, 0.0f);
	FRotator NewRotator = FRotator(0.0f, 0.0f, -40.0f);
	FVector BL1 = FVector(-20.0f, 410.0f, 270.0f);
	FVector BL2 = FVector(-40.0f, 410.0f, 270.0f);
	FVector BL3 = FVector(-60.0f, 410.0f, 270.0f);
	FVector NL1 = FVector(-20.0f, 400.0f, 260.0f);
	FVector NL2 = FVector(-40.0f, 400.0f, 260.0f);
	FVector NL3 = FVector(-60.0f, 400.0f, 260.0f);
	UInputComponent *InputComponent = nullptr;
public:	
	// Sets default values for this component's properties
	ULeverIinp();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void ActivateLever();
	const FHitResult GetFirstPhysicsBodyInReach();
	void SetInputComponent();
	FVector GetReachLineStart();

	FVector GetReachLineEnd();

	float RandomFloat(float a, float b);
	
};
