// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
#include "Camera/PlayerCameraManager.h"
#include "kismet/GameplayStatics.h"
#include "LevelStreamingCharacter.h"

AMyTriggerBox::AMyTriggerBox()
{
}

void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	auto cameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);

	DefaultCamera = cameraManager->GetViewTarget();

	blendType = CameraType::Default;

	OnBlendEnd.BindUObject(this, &AMyTriggerBox::OnBlendComplete);
	GetWorld()->GetFirstPlayerController()->PlayerCameraManager->OnBlendComplete().Add(OnBlendEnd);
}

void AMyTriggerBox::NotifyActorBeginOverlap(AActor* otherActor)
{
	Super::NotifyActorBeginOverlap(otherActor);

	auto player = Cast<ALevelStreamingCharacter>(otherActor);
	if (nullptr == player)
		return;
	auto playerController = Cast<APlayerController>(player->GetController());

	float blendTime = 2.f;
	playerController->SetViewTargetWithBlend(SecondCamera, blendTime, VTBlend_Linear, 0.f, true);
	
	blendType = CameraType::Blending;
	preCameraType = CameraType::Default;
	if (ball)
	{
		ball->FindComponentByClass<UStaticMeshComponent>()->SetSimulatePhysics(true);
	}
}

void AMyTriggerBox::NotifyActorEndOverlap(AActor* otherActor)
{
	Super::NotifyActorEndOverlap(otherActor);

	auto player = Cast<ALevelStreamingCharacter>(otherActor);
	if (nullptr == player)
		return;

	float blendTime = 2.f;

	blendType = CameraType::Blending;
	preCameraType = CameraType::Second;
	auto playerController = Cast<APlayerController>(player->GetController());
	playerController->SetViewTargetWithBlend(DefaultCamera, 2.f, VTBlend_Linear, 0.f, true);

}

void AMyTriggerBox::OnBlendComplete()
{
	
	if (preCameraType == CameraType::Default)
		blendType = CameraType::Second;
	else if (preCameraType == CameraType::Second)
		blendType = CameraType::Default;


}
