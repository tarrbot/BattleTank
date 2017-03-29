// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward Declaration
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private: 
	
	
	// Start the tank barrel towards the Crosshair
	void AimTowardsCrosshair();

	// Return an out parameter , true if hits landscape

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;
		
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.3333;
	
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
