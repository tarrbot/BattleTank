// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initilise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)

{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}





void UTankMovementComponent::IntendMoveFoward(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("intend move forward: %f"),Throw)

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	// TODO prevent cross over input
}