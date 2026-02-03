// Copyright (c) 2025 Max Harris
// Published by Procedural Architect

using UnrealBuildTool;

public class ProceduralBuildingsEditor : ModuleRules
{
	public ProceduralBuildingsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"PCG",
                "Slate",
                "SlateCore",
                "ProceduralBuildings"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				//"CoreUObject",
				//"Engine",
				//"Slate",
				//"SlateCore",
				//"PhysicsCore",
				//"NavigationSystem",
				//"GameplayTags",
				
				"PropertyPath",
                //"Projects",

                "UnrealEd",
				"PropertyEditor",
				"EditorStyle",
				"Projects",   

                "AppFramework",
				"ApplicationCore",
				"AssetDefinition",
				"AssetTools",
				"AssetRegistry",
				//"BlueprintGraph",
				"ContentBrowser",
				"DesktopWidgets",
				"DetailCustomizations",
				"DeveloperSettings",
				"EditorFramework",
				"EditorScriptingUtilities",
				"EditorStyle",
				"EditorSubsystem",
				"EditorWidgets",
				"GameProjectGeneration",
				"GraphEditor",
				"InputCore",
				"Kismet",
				"KismetWidgets",
				//"PCG",
				//"PropertyEditor",
				"RenderCore",
				//"Slate",
				//"SlateCore",
				"SourceControl",
				"StructUtilsEditor",
				"ToolMenus",
				"ToolWidgets",
				"TypedElementFramework",
				"TypedElementRuntime",
				//"UnrealEd",
				"LevelEditor",
				"SceneOutliner", 
				"AdvancedPreviewScene",
				"PCGEditor"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
