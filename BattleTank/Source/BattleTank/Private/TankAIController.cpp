// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Found Player: %s"), *(PlayerTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
}

// Called every Frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
		// Move Towards the Player

		// Aim Towards the Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
			// Fire if Ready
		
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank*  ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

