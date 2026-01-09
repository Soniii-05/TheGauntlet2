// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheGautlet2 : ModuleRules
{
	public TheGautlet2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"TheGautlet2",
			"TheGautlet2/Variant_Platforming",
			"TheGautlet2/Variant_Platforming/Animation",
			"TheGautlet2/Variant_Combat",
			"TheGautlet2/Variant_Combat/AI",
			"TheGautlet2/Variant_Combat/Animation",
			"TheGautlet2/Variant_Combat/Gameplay",
			"TheGautlet2/Variant_Combat/Interfaces",
			"TheGautlet2/Variant_Combat/UI",
			"TheGautlet2/Variant_SideScrolling",
			"TheGautlet2/Variant_SideScrolling/AI",
			"TheGautlet2/Variant_SideScrolling/Gameplay",
			"TheGautlet2/Variant_SideScrolling/Interfaces",
			"TheGautlet2/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
