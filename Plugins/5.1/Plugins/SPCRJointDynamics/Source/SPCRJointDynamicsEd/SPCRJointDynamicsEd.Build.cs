//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
using UnrealBuildTool;
using System.IO;

public class SPCRJointDynamicsEd : ModuleRules
{
    public SPCRJointDynamicsEd(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateIncludePaths.AddRange(new string[] {
            "SPCRJointDynamicsEd/Private"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "AssetTools",
            "BlueprintGraph",
            "AnimGraph",
            "Persona",
            "UnrealEd",
            "AnimGraphRuntime",
            "SlateCore",
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EditorFramework",
            "AnimationEditMode",
            "SPCRJointDynamics",
        });
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "UnrealEd",
            "AssetTools",
            "Slate",
            "SlateCore",
            "EditorStyle",
            "AppFramework",
            "MainFrame",
            "KismetWidgets",
            "LevelEditor",
            "PropertyEditor",
            "Projects",
            "BlueprintGraph",
            "AnimationEditMode",
            "SPCRJointDynamics",
        });
    }
}
