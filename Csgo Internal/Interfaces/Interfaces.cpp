
#include <Interfaces.h>
#include <iostream>

void Interfaces::SetupInterfaces()
{
	IBaseClientDLL =	GetInterfaceClass<void*>("VClient018", "client.dll");
	entityList =		GetInterfaceClass<IClientEntityList*>("VClientEntityList003", "client.dll"); 
	engineClient =		GetInterfaceClass<IVEngineClient*>("VEngineClient014", "engine.dll"); 
	modelInfo	=		GetInterfaceClass<IVModelInfo*>("VModelInfoClient004", "engine.dll"); 
	materialSystem =	GetInterfaceClass<IMaterialSystem*>("VMaterialSystem080", "materialsystem.dll"); 
	studioRenderer =	GetInterfaceClass<IStudioRenderer*>("VStudioRender026", "studiorender.dll"); 
	debugOverlay =		GetInterfaceClass<IVDebugOverlay*>("VDebugOverlay004", "engine.dll"); 
	engineTrace =		GetInterfaceClass<IEngineTrace*>("EngineTraceClient004", "engine.dll"); 
	globalVars =		**reinterpret_cast<GlobalVarsBase***>((*reinterpret_cast<uintptr_t**>(IBaseClientDLL))[11] + 10); 
	ClientModeShared =	**reinterpret_cast<void***>((*reinterpret_cast<uintptr_t**>(IBaseClientDLL))[10] + 5); 

}
