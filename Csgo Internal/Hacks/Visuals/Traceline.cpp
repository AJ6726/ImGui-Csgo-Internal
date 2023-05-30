

#include <Interfaces.h>
#include <ImGui_Wrappers.h>
#include <UConfigs.h>

enum TracelineOrigin : int
{
	TOP_SCREEN, 
	CENTER_SCREEN, 
	BOTTOM_SCREEN
};

enum TracelineTarget : int
{
	ENTITY_HEAD, 
	ENTITY_TORSO, 
	ENTITY_FEET
};

void DrawTraceline (CBaseEntity* entity, float tracelineColor[3])
{
	static Vector2 topScreen = { 960, 0 }; 
	static Vector2 centerScreen = { 960, 540 }; 
	static Vector2 bottomScreen = { 960, 1080 };

	Matrix_3x4 entityBones[128]; 
	if (entity->SetupBones(entityBones, 128, BONEMASK, Interfaces::globalVars->currentTime))
	{
		Vector3 wEntityHead = entityBones[8].Get3DPosition(); 
		Vector3 wEntityTorso = entityBones[7].Get3DPosition() - Vector3{ 0.f, 0.f, 10.f }; 
		Vector3 wEntityFeet = entity->GetAbsOrigin() - Vector3{ 0.f, 0.f, 4.f }; 

		switch (VisualConfig::tracelineTarget)
		{
		case ENTITY_HEAD: 
		{
			Vector2 sEntityHead = { 0 }; 
			if (!Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead))
			{
				if (VisualConfig::tracelineOrigin == TOP_SCREEN)
					ImGui_DrawLine(topScreen, sEntityHead, tracelineColor, VisualConfig::tracelineThickness);

				if (VisualConfig::tracelineOrigin == CENTER_SCREEN)
					ImGui_DrawLine(centerScreen, sEntityHead, tracelineColor, VisualConfig::tracelineThickness);

				if (VisualConfig::tracelineOrigin == BOTTOM_SCREEN)
					ImGui_DrawLine(bottomScreen, sEntityHead, tracelineColor, VisualConfig::tracelineThickness);
			}

		}break; 

		case ENTITY_TORSO: 
		{
			Vector2 sEntityTorso = { 0 }; 
			if (!Interfaces::debugOverlay->GetScreenPostion(wEntityTorso, sEntityTorso))
			{
				if (VisualConfig::tracelineOrigin == TOP_SCREEN)
					ImGui_DrawLine(topScreen, sEntityTorso, tracelineColor, VisualConfig::tracelineThickness);

				if (VisualConfig::tracelineOrigin == CENTER_SCREEN)
					ImGui_DrawLine(centerScreen, sEntityTorso, tracelineColor, VisualConfig::tracelineThickness);

				if (VisualConfig::tracelineOrigin == BOTTOM_SCREEN)
					ImGui_DrawLine(bottomScreen, sEntityTorso, tracelineColor, VisualConfig::tracelineThickness);
			}

		}break; 
		
		case ENTITY_FEET: 
		{
			Vector2 sEntityFeet = { 0 }; 
			if (!Interfaces::debugOverlay->GetScreenPostion(wEntityFeet, sEntityFeet))
			{
				if (VisualConfig::tracelineOrigin == TOP_SCREEN)
					ImGui_DrawLine(topScreen, sEntityFeet, tracelineColor, VisualConfig::tracelineThickness);

				if (VisualConfig::tracelineOrigin == CENTER_SCREEN)
					ImGui_DrawLine(centerScreen, sEntityFeet, tracelineColor, VisualConfig::tracelineThickness);

				if (VisualConfig::tracelineOrigin == BOTTOM_SCREEN)
					ImGui_DrawLine(bottomScreen, sEntityFeet, tracelineColor, VisualConfig::tracelineThickness);
			}
		}break; 

		}
		
	}
}