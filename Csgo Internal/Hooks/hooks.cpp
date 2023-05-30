
#include <D3D9_Hooks.h>
#include <Interface_hooks.h>
#include <Interfaces.h>
#include <MinHook.h>


void CreateHooks()
{
	Interfaces::SetupInterfaces(); 
	MH_Initialize();
	MH_CreateHook(GetVirtualFunction<void*>(direct3D9device_vtable, 42), &hEndScene, reinterpret_cast<void**>(&fnEndScene));
	MH_CreateHook(GetVirtualFunction<void*>(direct3D9device_vtable, 16), &hReset, reinterpret_cast<void**>(&fnReset)); ;
	MH_CreateHook(GetVirtualFunction<void*>(Interfaces::ClientModeShared, 24), &hCreateMove, reinterpret_cast<void**>(&fnCreateMove));
	MH_CreateHook(GetVirtualFunction<void*>(Interfaces::studioRenderer, 29), &hDrawModel, reinterpret_cast<void**>(&fnDrawModel)); 
	MH_EnableHook(MH_ALL_HOOKS);  
}

void DestroyHooks()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize(); 
}