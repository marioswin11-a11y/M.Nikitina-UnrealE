// Fill out your copyright notice in the Description page of Project Settings.


#include "NM_AttributeSet.h"
#include "GameplayEffectExtension.h"



UNM_AttributeSet::UNM_AttributeSet()
{
	Health = 100.f;
	MaxHealth = 100.f;
}

void UNM_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
}
