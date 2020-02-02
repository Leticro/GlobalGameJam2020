// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactable.h"
#include "GGJ2020Character.h"
#include "EnemyCharacter.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the interact range collider
	mInteractRange = CreateDefaultSubobject<USphereComponent>(TEXT("IntractRange"));
	mInteractRange->SetupAttachment(RootComponent);
	mInteractRange->SetSphereRadius(130);

	// Create health widget
	//mHealthbar = CreateDefaultSubobject<UWidgetComponent>(TEXT("Healthbar"));
	//mHealthbar->SetupAttachment(mInteractRange);
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get all overlapping Actors and store them in an array
	TArray<AActor*> CollectedActors;
	mInteractRange->GetOverlappingActors(CollectedActors);

    //UE_LOG(LogTemp, Warning, TEXT("%i\n"), CollectedActors.Num());
	// For each collected Actor
	for (int32 iCollected = 0; iCollected < CollectedActors.Num(); ++iCollected)
	{
		// Cast the actor to AInteractable
		AGGJ2020Character* player = Cast<AGGJ2020Character>(CollectedActors[iCollected]);
		// If the cast is successful
		if (player)
		{
			if (Health < 1.0f) Health += player->HEALTH_RECOVER_RATE * DeltaTime;
			else Health = 1.0f;
		}

		AEnemyCharacter* enemy = Cast<AEnemyCharacter>(CollectedActors[iCollected]);
		if (enemy)
		{
			if (Health > 0.0f) Health -= enemy->HEALTH_DECREASE_RATE * DeltaTime;
			else Health = 0.0f;
			//UE_LOG(LogTemp, Warning, TEXT("POI OVERLAP: %f"), enemy->HEALTH_DECREASE_RATE);
		}
	}
}
