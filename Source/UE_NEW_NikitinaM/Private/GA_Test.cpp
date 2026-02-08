// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_Test.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"

void UGA_Test::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	ACharacter* Character = Cast<ACharacter>(ActorInfo ? ActorInfo->AvatarActor.Get() : nullptr);
	if (!Character)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
		return;
	}

	const FVector Forward = Character->GetActorForwardVector();
	const float DashStrength = 1200.f;
	
	Character->LaunchCharacter(Forward * DashStrength, true, true);
	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
};

