#pragma once
#include <Interfaces.h>
struct IClientUnkown
{
	CBaseEntity* GetBaseEntity()
	{
		return CallVirtualFunction<CBaseEntity*>(this, 7);
	}
};
