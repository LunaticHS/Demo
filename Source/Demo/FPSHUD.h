// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h" 
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
protected:
    // ������������Ļ���ġ�
    UPROPERTY(EditDefaultsOnly)
    UTexture2D* CrosshairTexture;
public:
    // HUD���Ƶ���Ҫ���á�
    virtual void DrawHUD() override;
};