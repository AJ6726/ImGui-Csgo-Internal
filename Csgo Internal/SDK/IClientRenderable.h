#include <Interfaces.h>

struct IClientRenderable
{
	IClientUnkown* GetIClientUnkown()
	{
		return CallVirtualFunction<IClientUnkown*>(this, 0);
	}
};