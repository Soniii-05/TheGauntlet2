// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interactable.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class THEGAUTLET2_API AInteractableBase  : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AInteractableBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Material")
	FName ColorParameterName = "Color";

	UPROPERTY(EditDefaultsOnly, Category="Material")
	FLinearColor InitialColor;

	void SetColor(const FLinearColor& NewColor);
};
