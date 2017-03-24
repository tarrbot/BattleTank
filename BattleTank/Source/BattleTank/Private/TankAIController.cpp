// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every Frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
		// Move Towards the Player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim Towards the Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		// Fire if Ready
		ControlledTank->Fire(); // TODO limit firing rate

		
}

