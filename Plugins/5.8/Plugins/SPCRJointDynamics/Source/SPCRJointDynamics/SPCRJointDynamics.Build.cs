//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
using UnrealBuildTool;
using System.IO;

public class SPCRJointDynamics : ModuleRules
{
    public SPCRJointDynamics(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateIncludePathModuleNames.Add("TargetPlatform");

        PrivateIncludePaths.AddRange(
            new string[] {
                "SPCRJointDynamics/Private",
                // ... add other private include paths required here ...
            }
            );

        PrivateIncludePathModuleNames.AddRange(
            new string[] {
                "Settings"
            }
            );

        // Dependencies       
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "AnimGraphRuntime",
                // ... add other public dependencies that you statically link with here ...
            }
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "RHI",
                "RenderCore",
                "Renderer",

                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                // ... add private dependencies that you statically link with here ...
            });

    }
}
