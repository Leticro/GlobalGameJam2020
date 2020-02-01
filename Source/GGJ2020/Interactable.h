// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class GGJ2020_API AInteractable : public AActor
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable, meta = (AllowPrivateAccess = "true"))
		float Health = 1.0;

	// Sets default values for this actor's properties
	AInteractable();

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Interactable)
		class USphereComponent* mInteractRange;

	///** widget component */
	//UPROPERTY(VisibleDefaultsOnly, Category = Default)
	//	class UWidgetComponent* mHealthbar;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION()
	//	void OnOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
