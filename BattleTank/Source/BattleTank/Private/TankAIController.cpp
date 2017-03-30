// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every Frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	{
		// Move Towards the Player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim Towards the Player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		// Fire if Ready
		
	//	ControlledTank->Fire(); // TODO fix firing 

	}
}

