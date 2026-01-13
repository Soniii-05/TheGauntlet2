// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableBase.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

AInteractableBase::AInteractableBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (Mesh)
	{
		DynamicMaterial = Mesh->CreateDynamicMaterialInstance(0);

		if (DynamicMaterial)
		{
			DynamicMaterial->SetVectorParameterValue(
				ColorParameterName,
				InitialColor
			);
		}
	}
}

void AInteractableBase::SetColor(const FLinearColor& NewColor)
{
	if (DynamicMaterial)
	{
		DynamicMaterial->SetVectorParameterValue(
			ColorParameterName,
			NewColor
		);
	}
}