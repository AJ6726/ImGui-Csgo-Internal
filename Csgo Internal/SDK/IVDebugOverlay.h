#pragma once

struct IVDebugOverlay
{
	int GetScreenPostion(Vector3& world, Vector2& screen) 
	{
		
		return CallVirtualFunction<int, Vector3&, Vector2&>(this, 13, world, screen);
	}
};
