// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_Fireball.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

void UGA_Fireball::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData)
{
    

    AActor* Avatar = (ActorInfo && ActorInfo->AvatarActor.IsValid()) ? ActorInfo->AvatarActor.Get() : nullptr;
    
    if (!Avatar || !ProjectileClass)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    UWorld* World = Avatar->GetWorld();
    if (!World)
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    const FVector SpawnLocation = Avatar->GetActorLocation() + Avatar->GetActorForwardVector() * 100.f + FVector(0.f, 0.f, 50.f);
    const FRotator SpawnRotation = Avatar->GetActorRotation();

    FActorSpawnParameters Params;
    Params.Owner = Avatar;
    Params.Instigator = Cast<APawn>(Avatar);

    World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, Params);

    EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}