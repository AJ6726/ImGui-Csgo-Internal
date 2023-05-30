#include <UGlobal.h>

void GlobalHelper()
{
		CBaseEntity* localPlayer = Interfaces::entityList->GetClientEntity(Interfaces::engineClient->GetLocalPlayer());
		if (localPlayer)
		{
			Global::localPlayer = localPlayer;
		}
		else
		{
			localPlayer = nullptr;
		}
}