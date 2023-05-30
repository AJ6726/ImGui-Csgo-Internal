#include <Interfaces.h>
#include <ImGui_Wrappers.h>
#include <UConfigs.h>

enum HealthBarLocation : int
{
	LEFT_HEALTHBAR,
	RIGHT_HEALTHBAR, 
	TOP_HEALTHBAR, 
	BOTTOM_HEALTHBAR
};

void DrawHealthBar (CBaseEntity* entity)
{
	Matrix_3x4 entityBones[128];
	if (entity->SetupBones(entityBones, 128, BONEMASK, Interfaces::globalVars->currentTime))
	{
		Vector3 wEntityHead = entityBones[8].Get3DPosition() + Vector3{ 0.f, 0.f, 9.f };
		Vector3 wEntityFeet = entity->GetAbsOrigin() - Vector3{ 0.f, 0.f, 4.f };

		Vector2 sEntityHead = { 0 };
		Vector2 sEntityFeet = { 0 };
		if (!Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead) && !Interfaces::debugOverlay->GetScreenPostion(wEntityFeet, sEntityFeet))
		{
			float hieght = sEntityFeet.y - sEntityHead.y;
			float width = hieght * 0.29f;
			switch (VisualConfig::healthbarLocation)
			{
			case LEFT_HEALTHBAR:
			{
				Vector2 healthBarTop = { sEntityFeet.x - width - 5, sEntityFeet.y - (entity->GetHeatlth() * hieght / 100)};
				Vector2 healthBarBottom = { sEntityFeet.x - width - 5, sEntityFeet.y };
				ImGui_DrawLine(healthBarTop, healthBarBottom, { 0, 255, 0 }, 3.f);
			} break;

			case RIGHT_HEALTHBAR:
			{
				Vector2 healthBarTop = { sEntityHead.x + width + 4, sEntityFeet.y - (entity->GetHeatlth() * hieght / 100)};
				Vector2 healthBarBottom = { sEntityHead.x + width + 4, sEntityFeet.y };
				ImGui_DrawLine(healthBarTop, healthBarBottom, { 0, 255, 0 }, 3.f);
			} break; 

			case TOP_HEALTHBAR:
			{
				Vector2 healthbarLeft = { sEntityFeet.x - (entity->GetHeatlth() * width / 100), sEntityHead.y - 4.f};
				Vector2 healthBarRight = { sEntityHead.x + (entity->GetHeatlth() * width / 100), sEntityHead.y - 4.f };
				ImGui_DrawLine(healthbarLeft, healthBarRight, { 0, 255, 0 }, 3.f); 
			}break; 
				
			case BOTTOM_HEALTHBAR: 
			{
				Vector2 healthBarLeft = { sEntityFeet.x - (entity->GetHeatlth() * width / 100), sEntityFeet.y + 3.f };
				Vector2 healthBarRight = { sEntityHead.x + (entity->GetHeatlth() * width / 100), sEntityFeet.y + 3.f };
				ImGui_DrawLine(healthBarLeft, healthBarRight, { 0, 255, 0 }, 3.f); 
			}break; 
				
			}
		}
	}
}
