// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_NEW_NikitinaM : ModuleRules
{
	public UE_NEW_NikitinaM(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities", "GameplayTags", "GameplayTasks" });

	}

}
