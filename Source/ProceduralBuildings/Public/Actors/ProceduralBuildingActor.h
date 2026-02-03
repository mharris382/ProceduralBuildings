// Copyright (c) 2025 Max Harris
// Published by Procedural Architect

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCGGraph.h"
#include "Components/BoxComponent.h"
#include "ProceduralBuildingActor.generated.h"

UCLASS()
class PROCEDURALBUILDINGS_API AProceduralBuildingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralBuildingActor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Core")
	void ComputeBoundingBox(FVector& BoundsMin, FVector& BoundsMax);

	UFUNCTION(BlueprintCallable, Category = "Core")
	void UpdateBounds();

protected:
	virtual void ComputeBoundingBox_Implementation(FVector& BoundsMin, FVector& BoundsMax);
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core", meta = (Tooltip = "Shared Actor Seed for convienence to be used in PCG Graphs with randomness.  This is only applicable with override graphs, the default behavior is not random", EditCondition = "!DisableAllOverrideGraphs"))
	int Seed = 2026;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core", meta = (Tooltip = "Padding to be added to the computed bounding box of the pipe actor"))
	FVector BoundsPadding = FVector(0.0f, 0.0f, 0.0f);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* BoundingBox;

#pragma region OverrideGraphs


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core|OverrideGraphs", meta = (
		Tooltip = "Use this to disable all override graphs for this asset.  Useful for debugging."))
	bool DisableAllOverrideGraphs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core|OverrideGraphs", meta = (InlineEditConditionToggle, EditCondition = "!DisableAllOverrideGraphs",
		Tooltip = "Enables a Pre-Spawn Override Graph that processes ALL points before any meshes are spawned. This graph has global authority and can filter, merge, or modify points prior to the normal spawn behavior."))
	bool bEnablePreSpawnOverride;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core|OverrideGraphs", meta = (EditCondition = "bEnablePreSpawnOverride",
		Tooltip = "Graph executed before spawning begins. Receives the complete point set and must output the final points used for spawning. Use this to globally filter, merge, or preprocess points before any Spawn Override Graphs are evaluated."))
	TScriptInterface<UPCGGraphInterface> PreSpawnOverride;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core|OverrideGraphs", meta = (InlineEditConditionToggle, EditCondition = "!DisableAllOverrideGraphs",
		Tooltip = "Enables a Post-Spawn Override Graph that runs after all meshes have been spawned. This graph is read-only and cannot modify spawn data, but can add secondary details or perform analysis based on the spawned results."))
	bool bEnablePostSpawnOverride;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core|OverrideGraphs", meta = (EditCondition = "bEnablePostSpawnOverride",
		Tooltip = "Graph executed after all spawning is complete. Receives spawned meshes as input and may spawn additional effects, decorations, or data. This graph cannot alter the original spawn results."))
	TScriptInterface<UPCGGraphInterface> PostSpawnOverride;

#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core", AdvancedDisplay, meta = (Tooltip = "If enabled, building spline will not spawn it's own points.   Instead the points will be output with the assumption that another pcg world actor will spawn them instead using SpawnBuilding.  NOTE: if no actor exists that calls SpawnBuildingPoints, the building won't be spawned"))
	bool IsBatched;
};
