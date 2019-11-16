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

        PublicIncludePaths.AddRange(new string[] {

        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "AssetTools",
            "BlueprintGraph",
            "SPCRJointDynamics",
            "AnimGraph",
            "Persona"
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
            "SPCRJointDynamics",
        });
    }
}
