// Copyright (c) 2025 Max Harris
// Published by Procedural Architect

#include "Customizations/PluginCustomizations.h"
#include "AssetToolsModule.h"
//#include "Customizations/ShelfClutterCustomization.h"
//#include "Customizations/GrammarModuleCustomization.h"
//#include "Customizations/ShelfActorCustomization.h"
#include "PropertyEditorModule.h"

namespace PluginCustomizations
{
    void RegisterDetailCustomizations()
    {
        // FPropertyEditorModule& PropEd = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

        // PropEd.RegisterCustomPropertyTypeLayout("ShelfClutter",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FShelfClutterCustomization::MakeInstance));
        // PropEd.RegisterCustomPropertyTypeLayout("ShelfClutterGrammarModule",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FGrammarModuleCustomization::MakeInstance));

        // PropEd.RegisterCustomClassLayout("ShelfClutterActor", FOnGetDetailCustomizationInstance::CreateStatic(&FShelfClutterActorCustomization::MakeInstance));
    }

    void UnregisterDetailCustomizations()
    {
        // if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
        // {
        //     FPropertyEditorModule& PropertyEditor =
        //         FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

        //     PropertyEditor.UnregisterCustomClassLayout("ShelfClutterActor");
        // }
    }
} // namespace ProceduralBuildingsCustomizations