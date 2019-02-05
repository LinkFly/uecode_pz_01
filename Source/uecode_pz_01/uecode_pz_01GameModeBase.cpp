// Fill out your copyright notice in the Description page of Project Settings.

#include "uecode_pz_01GameModeBase.h"
#include "Runtime/Core/Public/Misc/OutputDeviceNull.h"

void Auecode_pz_01GameModeBase::StartPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), TEXT("TEST-TEST"));

	FOutputDeviceNull outDevNull;
	this->CallFunctionByNameWithArguments(TEXT("Test"), outDevNull, this, true);

	UFloatProperty* FloatProp = FindField<UFloatProperty>(this->GetClass(), TEXT("TestFloat"));
	if (FloatProp) {
		float TestFloat = FloatProp->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("TestFloat = %f"), TestFloat);

		FloatProp->SetPropertyValue_InContainer(this, TestFloat + 100.0f);

		TestFloat = FloatProp->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("TestFloat (after changed) = %f"), TestFloat);
	}
}
