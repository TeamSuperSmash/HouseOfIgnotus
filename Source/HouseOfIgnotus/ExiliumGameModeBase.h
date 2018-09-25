// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ExiliumGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HOUSEOFIGNOTUS_API AExiliumGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
    virtual void StartPlay() override;	
};