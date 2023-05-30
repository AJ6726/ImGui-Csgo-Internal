
#include <Interfaces.h>
#include <CUserCmd.h>
#include <UMath.h>
#include <iostream>

 
void Triggerbot(CBaseEntity* localPlayer, CUserCmd* userCmd)
{
	Vector3 eyePostion = localPlayer->GetEyePosition();
	Vector3 aimPucnh = localPlayer->GetAimPunch();

	Vector3 postionalVector = ToPositionalVector(userCmd->viewAngles + aimPucnh);
	Vector3 rayDestination = eyePostion + postionalVector * Vector3{ 10000.f, 10000.f, 10000.f };

	CTraceFilter traceFilter = CTraceFilter(localPlayer);
	Trace trace;

	Interfaces::engineTrace->TraceRay({ eyePostion, rayDestination }, TRACEMASK, &traceFilter, &trace);
	
	static bool fix = false; 

	if (!fix)
	{
		std::cout << "Fix this shit lmao" << std::endl; 
		fix = true; 
	}

	if (trace.entity)
	{
		if (trace.entity->IsPlayer())
		{
			userCmd->buttons |= IN_ATTACK;
		}
	}
}