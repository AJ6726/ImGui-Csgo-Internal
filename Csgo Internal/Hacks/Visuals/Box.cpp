#include <Interfaces.h>
#include <ImGui_Wrappers.h>
#include <UConfigs.h>

void DrawBox (CBaseEntity* entity, float boxColor[3])
{
	Matrix_3x4 entityBones[128]; 
	if (entity->SetupBones(entityBones, 128, BONEMASK, Interfaces::globalVars->currentTime))
	{
		Vector3 wEntityHead = entityBones[8].Get3DPosition() + Vector3{0.f, 0.f, 9.f};
		Vector3 wEntityFeet = entity->GetAbsOrigin() - Vector3{ 0.f, 0.f, 4.f }; 

		Vector2 sEntityHead = { 0 }; 
		Vector2 sEntityFeet = { 0 }; 
		if (!Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead) && !Interfaces::debugOverlay->GetScreenPostion(wEntityFeet, sEntityFeet)); 
		{
			Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead); 
			
			float hieght = sEntityFeet.y - sEntityHead.y; 
			float width = hieght * 0.29f; 

			Vector2 topRight = { sEntityHead.x + width, sEntityHead.y }; 
			Vector2 bottomLeft = { sEntityFeet.x - width, sEntityFeet.y }; 
			
			ImGui_DrawBox(topRight, bottomLeft, boxColor, VisualConfig::boxRounding, VisualConfig::boxThickness);
		}
	}
}
void DrawCornerBox(CBaseEntity* entity, float corner_box_color[3])
{
	Matrix_3x4 entityBones[128];
	if (entity->SetupBones(entityBones, 128, BONEMASK, Interfaces::globalVars->currentTime))
	{
		Vector3 wEntityHead = entityBones[8].Get3DPosition() + Vector3{ 0.f, 0.f, 9.f };
		Vector3 wEntityFeet = entity->GetAbsOrigin() - Vector3{ 0.f, 0.f, 4.f };

		Vector2 sEntityHead = { 0 };
		Vector2 sEntityFeet = { 0 };
		if (!Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead) && !Interfaces::debugOverlay->GetScreenPostion(wEntityFeet, sEntityFeet));
		{
			float hieght = sEntityFeet.y - sEntityHead.y;
			float width = hieght * 0.29f;

			Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead); 
			Vector2 topRight = { sEntityHead.x + width, sEntityHead.y };
			Vector2 top_parentTopRight = { topRight.x - (width / VisualConfig::cornerBox_topbottomSpace), topRight.y };
			Vector2 side_parentTopRight = { topRight.x, topRight.y + (width / VisualConfig::cornerBox_sideSpace) };

			Vector2 topLeft = { sEntityFeet.x - width, sEntityHead.y };
			Vector2 top_parentTopLeft = { topLeft.x + (width / VisualConfig::cornerBox_topbottomSpace), topLeft.y };
			Vector2 side_parentTopLeft = { topLeft.x, topLeft.y + (width / VisualConfig::cornerBox_sideSpace) };

			Vector2 bottomRight = { sEntityHead.x + width, sEntityFeet.y };
			Vector2 bottom_parentBottomRight = { bottomRight.x - (width / VisualConfig::cornerBox_topbottomSpace), bottomRight.y };
			Vector2 side_parentBottomRight = { bottomRight.x, bottomRight.y - (width / VisualConfig::cornerBox_sideSpace) };

			Vector2 bottomLeft = { sEntityFeet.x - width, sEntityFeet.y };
			Vector2 bottom_parentBottomLeft = { bottomLeft.x + (width / VisualConfig::cornerBox_topbottomSpace), bottomLeft.y };
			Vector2 side_parentBottomleft = { bottomLeft.x, bottomLeft.y - (width / VisualConfig::cornerBox_sideSpace) };

			ImGui_DrawLine(topRight, top_parentTopRight, corner_box_color, VisualConfig::cornerBoxThickness);
			ImGui_DrawLine(topRight, side_parentTopRight, corner_box_color, VisualConfig::cornerBoxThickness);

			ImGui_DrawLine(topLeft, top_parentTopLeft, corner_box_color, VisualConfig::cornerBoxThickness);
			ImGui_DrawLine(topLeft, side_parentTopLeft, corner_box_color, VisualConfig::cornerBoxThickness);

			ImGui_DrawLine(bottomRight, bottom_parentBottomRight, corner_box_color, VisualConfig::cornerBoxThickness);
			ImGui_DrawLine(bottomRight, side_parentBottomRight, corner_box_color, VisualConfig::cornerBoxThickness); 

			ImGui_DrawLine(bottomLeft, bottom_parentBottomLeft, corner_box_color, VisualConfig::cornerBoxThickness);
			ImGui_DrawLine(bottomLeft, side_parentBottomleft, corner_box_color, VisualConfig::cornerBoxThickness);

		}
	}
}