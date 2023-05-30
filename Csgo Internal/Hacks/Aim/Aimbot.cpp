#include <Interfaces.h>
#include <CUserCmd.h>
#include <UGlobal.h>
#include <cmath>
#include <UMath.h>
#include <UConfigs.h>
CBaseEntity* GetClosestEnemy()
{
	float closestDistance = 100000.f; 
	int closestEntityIndex = 1; 

	for (int i = 1; i < 64; i++)
	{
		CBaseEntity* entity = Interfaces::entityList->GetClientEntity(i);

		if(entity && entity != Global::localPlayer)
		{
			if (entity->GetTeam() != Global::localPlayer->GetTeam() && entity->GetHeatlth() > 0)
			{
				Vector3 wLocalFeet = Global::localPlayer->GetAbsOrigin();
				Vector3 wEntityFeet = entity->GetAbsOrigin();

				Vector3 wDeltaFeet = wEntityFeet - wLocalFeet;
				float currentDistance = sqrtf((pow(wDeltaFeet.x, 2) + pow(wDeltaFeet.y, 2)));
				if (closestDistance > currentDistance)
				{
					closestDistance = currentDistance;
					closestEntityIndex = i;
				}
			}
		}

	}

	return Interfaces::entityList->GetClientEntity(closestEntityIndex); 
}

bool shoot = false; 
void Aimbot()
{
	CBaseEntity* enemy = GetClosestEnemy(); 

	if (enemy != nullptr)
	{
		Vector3 wLocalEye = Global::localPlayer->GetEyePosition();
		Vector3 wEnemyEye = enemy->GetEyePosition();

		Vector3 wDeltaEye = wEnemyEye - wLocalEye;

		float pitchAngle = RadianToDegree(-asin(wDeltaEye.z / sqrtf(pow(wDeltaEye.x + wDeltaEye.y, 2))));
		float yawAngle = RadianToDegree(atan2(wDeltaEye.y, wDeltaEye.x));

		Vector3 viewAngles = { }; 
		Interfaces::engineClient->GetViewAngles(viewAngles);
		
		Vector3 newViewAngles = { pitchAngle, yawAngle, 0.f };
		
		Vector3 deltaViewAngles = newViewAngles - viewAngles; 

		Vector3 finalViewAngles = viewAngles + (deltaViewAngles / Vector3{ AimbotConfig::Ysmoothness, AimbotConfig::Xsmoothness , 0.f }); 

		if(shoot)
			Interfaces::engineClient->SetViewAngles(finalViewAngles);
	}

}