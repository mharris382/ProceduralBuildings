// Copyright (c) 2025 Max Harris
// Published by Procedural Architect

#pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class FProceduralBuildingsEditorModule : public IModuleInterface
{
   public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	protected:
	
	void RegisterMenuExtensions();
	void UnregisterMenuExtensions();
};