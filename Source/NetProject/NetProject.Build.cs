// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NetProject : ModuleRules
{
	public NetProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay"
		, "GameplayAbilities"});
	}
}
