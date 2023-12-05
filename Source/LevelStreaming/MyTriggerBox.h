// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */

DECLARE_DELEGATE(BlendEnd);

UENUM(BlueprintType)enum class CameraType : uint8
{

	Default = 0,
	Second,
	Blending,
};

UCLASS()
class LEVELSTREAMING_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()


public:
	AMyTriggerBox();

protected:
	virtual void BeginPlay();


public:
	UFUNCTION()

	virtual void NotifyActorBeginOverlap(AActor* otherActor);
	virtual void NotifyActorEndOverlap(AActor* otherActor);

	void OnBlendComplete();



	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> ball;

	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> DefaultCamera;

	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> SecondCamera;

	UPROPERTY(EditAnywhere)
	CameraType blendType;

	UPROPERTY(EditAnywhere)
	CameraType preCameraType;

	BlendEnd OnBlendEnd;
	
};
