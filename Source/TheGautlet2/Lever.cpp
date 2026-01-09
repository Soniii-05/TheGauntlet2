#include "Lever.h"
#include "Components/StaticMeshComponent.h"

ALever::ALever()
{
	PrimaryActorTick.bCanEverTick = false;

	// Creazione della mesh
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeverMesh"));
	RootComponent = MeshComp;
}

void ALever::BeginPlay()
{
	Super::BeginPlay();

	// Creazione Materiale Dinamico al volo
	if (MeshComp)
	{
		UMaterialInterface* BaseMaterial = MeshComp->GetMaterial(0);
		if (BaseMaterial)
		{
			DynamicMat = UMaterialInstanceDynamic::Create(BaseMaterial, this);
			MeshComp->SetMaterial(0, DynamicMat);
			
			// Imposta colore iniziale (Rosso)
			DynamicMat->SetVectorParameterValue(FName("Color"), ColorIdle);
		}
	}
};

void ALever::Interact_Implementation(AActor* Interactor)
{
	// Se è già attiva, non fare nulla (Logica "One-Shot")
	if (bIsActivated) return;

	bIsActivated = true;
	UE_LOG(LogTemp, Log, TEXT("Leva attivata da: %s"), *Interactor->GetName());

	// 1. Cambia Colore in Verde
	if (DynamicMat)
	{
		DynamicMat->SetVectorParameterValue(FName("Color"), ColorActivated);
	}

	// 2. Attiva Piattaforme Orbitanti (Chiamata a funzione Blueprint)
	if (PlatformPivot)
	{
		UFunction* Func = PlatformPivot->FindFunction(FName("ActivatePlatform"));
		if (Func)
		{
			PlatformPivot->ProcessEvent(Func, nullptr);
		}
	}

	// 3. Apri Porta (Chiamata a funzione Blueprint)
	if (DoorActor)
	{
		UFunction* Func = DoorActor->FindFunction(FName("OpenDoor"));
		if (Func)
		{
			DoorActor->ProcessEvent(Func, nullptr);
		}
	}

	// 4. Disattiva Torretta (Supponendo che la torretta abbia una funzione C++ o BP)
	if (TurretActor)
	{
		UFunction* Func = TurretActor->FindFunction(FName("DeactivateTemporarily"));
		if (Func)
		{
			TurretActor->ProcessEvent(Func, nullptr);
		}
	}
}

