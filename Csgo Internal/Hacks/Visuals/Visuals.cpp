#include <Interfaces.h>
#include <UMatrix.h>
#include <UConfigs.h>
#include <UGlobal.h>
#include <imgui.h>

extern void DrawBox (CBaseEntity* entity, float corner_box_color[3]);
extern void DrawHealthBar (CBaseEntity* entity); 
extern void DrawSkeleton (CBaseEntity* entity, float skeletonColor[3]);
extern void DrawHeadCircle(CBaseEntity* entity, bool filledCircle, float circleColor[3]); 
extern void DrawTraceline (CBaseEntity* entity, float tracelineColor[3]);
extern void DrawCornerBox(CBaseEntity* entity, float corner_box_color[3]);
extern void DrawNames(int entityIndex, CBaseEntity* entity, float textColor[3]);

void RenderEsp()
{
	if (Global::localPlayer && Interfaces::engineClient->IsInGame())
	{
		for (int i = 1; i < 64; i++)
		{
			CBaseEntity* entity = Interfaces::entityList->GetClientEntity(i);

			if (entity && entity != Global::localPlayer)
			{

				if (entity->GetTeam() != Global::localPlayer->GetTeam() && entity->GetHeatlth() > 0)
				{
					if (VisualConfig::enemyBox)
						DrawBox(entity, VisualConfig::enemyColor);

					if (VisualConfig::enemyCornerBox)
						DrawCornerBox(entity, VisualConfig::enemyColor);

					if (VisualConfig::enemyHealthbar)
						DrawHealthBar(entity);

					if (VisualConfig::enemySkeleton)
						DrawSkeleton(entity, VisualConfig::enemyColor);

					if (VisualConfig::enemyTracelines)
						DrawTraceline(entity, VisualConfig::enemyColor);

					if (VisualConfig::enemyNames)
						DrawNames(i, entity, VisualConfig::enemyColor); 

					if (VisualConfig::enemyHeadCircle || VisualConfig::enemyFilledHeadCircle)
						DrawHeadCircle(entity, VisualConfig::enemyFilledHeadCircle, VisualConfig::enemyColor);
				}
				if (entity->GetTeam() == Global::localPlayer->GetTeam() && entity->GetHeatlth() > 0)
				{
					if (VisualConfig::teamBox)
						DrawBox(entity, VisualConfig::teamColor);

					if (VisualConfig::teamCornerBox)
						DrawCornerBox(entity, VisualConfig::teamColor);

					if (VisualConfig::teamHealthbar)
						DrawHealthBar(entity);

					if (VisualConfig::teamSkeleton)
						DrawSkeleton(entity, VisualConfig::teamColor);

					if (VisualConfig::teamTracelines)
						DrawTraceline(entity, VisualConfig::teamColor);

					if (VisualConfig::teamNames)
						DrawNames(i, entity, VisualConfig::teamColor); 

					if (VisualConfig::teamHeadCircle || VisualConfig::enemyFilledHeadCircle )
						DrawHeadCircle(entity, VisualConfig::teamFilledHeadCircle, VisualConfig::teamColor);
				}

			}
		}
	}
	
}

