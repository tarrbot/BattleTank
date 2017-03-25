// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{

	if (!ensure(GetControlledTank())) {return;}
	
	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocation(HitLocation))// is going to line trace
	{
		GetControlledTank()->AimAt(HitLocation);
		
			// if it hits the landscape
				// do the next video
	}
}	

// Get world location from crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find Crosshair Position in Pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
		
		
	FVector LookDirection;
	// DE-PROJECT the screen position of the cross hair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line Trace along that look direction, and see what we hit to a maximum range
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}



bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const 
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if ( GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		
		)
	{
	
		HitLocation = HitResult.Location;
		return true;

	}
	HitLocation = FVector(0);
	return false;
		
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const

{
	FVector CameraWorldLocation;
return	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

