#pragma once
#include <UInterfaces.h>
#include <UVector.h>


#include <IVModelInfo.h>
#include <CBaseEntity.h>
#include <IClientEntityList.h>
#include <IMaterialSystem.h>
#include <IVDebugOverlay.h>
#include <IVEngineClient.h>
#include <GlobalVarsBase.h>
#include <IEngineTrace.h>
#include <IClienUnkown.h>
#include <IClientRenderable.h>
#include <IStudioRenderer.h>

namespace Interfaces
{
	void SetupInterfaces(); 

	inline IClientEntityList* entityList = nullptr; 
	inline IVEngineClient* engineClient = nullptr;
	inline IVModelInfo* modelInfo = nullptr; 
	inline IMaterialSystem* materialSystem = nullptr; 
	inline IStudioRenderer* studioRenderer = nullptr; 
	inline IVDebugOverlay* debugOverlay = nullptr; 
	inline GlobalVarsBase* globalVars = nullptr; 
	inline IEngineTrace* engineTrace = nullptr; 
	inline void* IBaseClientDLL = nullptr; 
	inline void* ClientModeShared = nullptr; 

	inline int interfaceCount = 10; 

}


