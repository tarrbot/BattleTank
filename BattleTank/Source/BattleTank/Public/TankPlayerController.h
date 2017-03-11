// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private: 

	ATank* GetControlledTank() const;
	
	// Start the tank barrel towards the Crosshair
	void AimTowardsCrosshair();

	// Return an out parameter , true if hits landscape

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;
		
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333;
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
