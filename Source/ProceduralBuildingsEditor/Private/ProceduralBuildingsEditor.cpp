// Copyright (c) 2025 Max Harris
// Published by Procedural Architect

#include "ProceduralBuildingsEditor.h"

#include "Customizations/PluginCustomizations.h"
#include "PropertyEditorModule.h"
#include "AssetRegistry/AssetData.h"
//#include "Styles/ShelfClutterStyle.h"
#include "Editor.h"
#include "ContentBrowserMenuContexts.h"


#define LOCTEXT_NAMESPACE "FProceduralBuildingsEditorModule"

void FProceduralBuildingsEditorModule::StartupModule()
{
   
    PluginCustomizations::RegisterDetailCustomizations();

	//FShelfClutterStyle::Initialize();
	RegisterMenuExtensions();
     // FPropertyEditorModule& PropEd = 
    //     FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

    //     PropEd.RegisterCustomPropertyTypeLayout("ShelfClutter",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FShelfClutterCustomization::MakeInstance));
}

void FProceduralBuildingsEditorModule::ShutdownModule()
{
	//FShelfClutterStyle::Shutdown();
	UnregisterMenuExtensions();
//     if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
//     {
//         FPropertyEditorModule& PropEd =
//             FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

//         PropEd.UnregisterCustomPropertyTypeLayout("ShelfClutter");
//     }
}

void FProceduralBuildingsEditorModule::RegisterMenuExtensions()
{
	
}

void FProceduralBuildingsEditorModule::UnregisterMenuExtensions()
{
	UToolMenus::UnregisterOwner(this);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FProceduralBuildingsEditorModule, ProceduralBuildingsEditor)