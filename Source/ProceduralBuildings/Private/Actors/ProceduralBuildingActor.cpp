// Copyright (c) 2025 Max Harris
// Published by Procedural Architect


#include "Actors/ProceduralBuildingActor.h"
#include "Components/SplineComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/KismetMathLibrary.h"

namespace
{
	static void GetMinMax(FVector location, FVector& Min, FVector& Max)
	{
		Min.X = FMath::Min(Min.X, location.X);
		Min.Y = FMath::Min(Min.Y, location.Y);
		Min.Z = FMath::Min(Min.Z, location.Z);
		Max.X = FMath::Max(Max.X, location.X);
		Max.Y = FMath::Max(Max.Y, location.Y);
		Max.Z = FMath::Max(Max.Z, location.Z);
	}
}

// Sets default values
AProceduralBuildingActor::AProceduralBuildingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	BoundingBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoundingBox->SetupAttachment(RootComponent);
	BoundingBox->SetCollisionProfileName(TEXT("NoCollision"));


	UpdateBounds();

	Tags.AddUnique(FName("ProceduralBuilding"));
	if (IsBatched)
	{
		Tags.AddUnique(FName("Batched"));
	}
}

void AProceduralBuildingActor::ComputeBoundingBox_Implementation(FVector& BoundsMin, FVector& BoundsMax)
{
	USplineComponent* Spline = FindComponentByClass<USplineComponent>();
	if (!BoundingBox || !Spline)
	{
		BoundsMin = FVector(-100, -100, -100);
		BoundsMax = -BoundsMin;
		return;
	}
	int32 cnt = Spline->GetNumberOfSplinePoints();
	BoundsMax = BoundsMax = Spline->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::Local);
	for (int i = 0; i < cnt; i++)
	{
		FVector loc = Spline->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Local);
		GetMinMax(loc, BoundsMin, BoundsMax);
	}

}

void AProceduralBuildingActor::UpdateBounds()
{
	FVector Min;
	FVector Max;
	ComputeBoundingBox(Min, Max);
	FVector Extents = ((Max - Min) * 0.5f) + BoundsPadding;
	FVector BoxOffset = (Extents + Min);
	BoundingBox->SetBoxExtent(Extents);
	BoundingBox->SetRelativeLocation(BoxOffset);
}


