#include <CUserCmd.h>
#include <UGlobal.h>

void BHop(CUserCmd* userCmd)
{
	if (!(*(reinterpret_cast<int*>(Global::localPlayer + 0x104)) & FL_ONGROUND))
	{
		userCmd->buttons &= ~IN_JUMP;
	}
}