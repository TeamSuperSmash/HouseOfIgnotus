// Fill out your copyright notice in the Description page of Project Settings.

#include "FogCube_Manager.h"


// Sets default values
AFogCube_Manager::AFogCube_Manager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFogCube_Manager::BeginPlay()
{
	Super::BeginPlay();
	isCompleted = false;
}

// Called every frame
void AFogCube_Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFogCube_Manager::InactivateAllFog()
{
	for (int i = 0; i < fogCubeList.Num(); i++)
	{
		if (fogCubeList[i] != nullptr)
		{
			fogCubeList[i]->isActive = false;
		}
	}
}

void AFogCube_Manager::CheckCurrent(AFogCube* cube)
{
	if (current != nullptr)
	{
		//current->Reduce(cube);
		InactivateAllFog();
		cube->Spread();
		current = cube;
	}
}

int AFogCube_Manager::CheckProgress()
{
	int count = 0;
	for (int i = 0; i < fogRoomList.Num(); i++)
	{
		if (fogRoomList[i]->isNormalized)
		{
			count++;
		}
		else
		{
			return count;
		}
	}

	return count;
}

