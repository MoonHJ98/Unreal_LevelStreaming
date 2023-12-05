// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LevelStreaming : ModuleRules
{
	public LevelStreaming(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
