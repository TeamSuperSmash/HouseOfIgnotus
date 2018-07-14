// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI_Bot_Character.generated.h"

UCLASS()
class EXILIUM_API AAI_Bot_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_Bot_Character();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint* NextWaypoint;

	//Function declared in c++ but defined inside blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = CustomStuff)
		void QTEStart(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent, Category = CustomStuff)
		void SwitchQTEType();

	UFUNCTION(BlueprintCallable, Category = CustomStuff)
		void EventFailQTE();

	UFUNCTION(BlueprintCallable, Category = CustomStuff)
		void HeartbeatSuccess();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CustomStuff)
		bool bIsPlayerDetected = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
