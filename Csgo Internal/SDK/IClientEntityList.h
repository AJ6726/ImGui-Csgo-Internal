#pragma once
#include <Interfaces.h>

struct IClientEntityList
{
	CBaseEntity* GetClientEntity(int entityIndex) { return CallVirtualFunction<CBaseEntity*, int>(this, 3, entityIndex); }
};
