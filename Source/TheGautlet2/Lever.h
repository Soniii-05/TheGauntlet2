

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"          // La tua interfaccia
#include "Lever.generated.h"

UCLASS()
class THEGAUTLET2_API ALever : public AActor, public IInteractable
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ALever();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// --- COMPONENTI ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// --- RIFERIMENTI (Punto 3.B) ---
	// Usiamo AActor per massima flessibilità, richiameremo le funzioni via nome o interfaccia
	UPROPERTY(EditInstanceOnly, Category = "The Gauntlet | Connections")
	AActor* PlatformPivot;

	UPROPERTY(EditInstanceOnly, Category = "The Gauntlet | Connections")
	AActor* DoorActor;

	UPROPERTY(EditInstanceOnly, Category = "The Gauntlet | Connections")
	AActor* TurretActor;

	// --- FEEDBACK VISIVO (Punto 2.3) ---
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMat;

	UPROPERTY(EditAnywhere, Category = "The Gauntlet | Visuals")
	FLinearColor ColorIdle = FLinearColor::Red;

	UPROPERTY(EditAnywhere, Category = "The Gauntlet | Visuals")
	FLinearColor ColorActivated = FLinearColor::Green;

private:
	bool bIsActivated = false;
	
public:	
	// Implementazione obbligatoria dell'interfaccia
	virtual void Interact_Implementation(AActor* Interactor) ;

};
