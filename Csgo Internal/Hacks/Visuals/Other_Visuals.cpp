
#include <Interfaces.h>
#include <ImGui_Wrappers.h>
#include <imgui.h>
#include <iostream>
#include <UConfigs.h>

extern ImFont* calibrilFont; 

void DrawNames(int entityIndex, CBaseEntity* entity, float textColor[3])
{
	Matrix_3x4 boneMatrix[128]; 
	if (entity->SetupBones(boneMatrix, 128, BONEMASK, Interfaces::globalVars->currentTime))
	{
		Vector3 wEntityHead = boneMatrix[8].Get3DPosition() + Vector3{ 0.f, 0.f, 12.f }; 
		Vector3 wEntityFeet = entity->GetAbsOrigin() - Vector3{ 0.f, 0.f, 6.f }; 

		Vector2 sEntityHead = { 0 };
		Vector2 sEntityFeet = { 0 }; 
		if (!Interfaces::debugOverlay->GetScreenPostion(wEntityFeet, sEntityFeet) && !Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead))
		{
			float width = (sEntityFeet.y - sEntityHead.y) * 0.30f; 
			PlayerInfo playerInfo = { 0 }; 
			if (Interfaces::engineClient->GetPlayerInfo(entityIndex, &playerInfo))
			{
				std::string playerName = playerInfo.name;

				ImGui::PushFont(calibrilFont);
				ImGui::GetBackgroundDrawList()->AddText({ sEntityHead.x + width + 6, sEntityHead.y }, ImColor{ textColor[0], textColor[1], textColor[3]}, playerName.c_str());
				ImGui::PopFont();
			}
		}
	}

}
void DrawHeadCircle(CBaseEntity* entity, bool filledCircle, float circleColor[3])
{
	Matrix_3x4 entityBones[128]; 
	if (entity->SetupBones(entityBones, 128, BONEMASK, Interfaces::globalVars->currentTime)) 
	{
		Vector3 wEntityHead = entityBones[8].Get3DPosition(); 
		Vector3 wEntityNeck = entityBones[7].Get3DPosition(); 
		
		Vector2 sEntityHead = { 0 }; 
		Vector2 sEntityNeck = { 0 }; 
		if (!Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead) && !Interfaces::debugOverlay->GetScreenPostion(wEntityNeck, sEntityNeck))
		{
			Interfaces::debugOverlay->GetScreenPostion(wEntityNeck, sEntityNeck); 

			float circleRadius = (sEntityNeck.y - sEntityHead.y) * 1.3f; 

			if (0.1f < circleRadius < 9999.f); 
			{
				Interfaces::debugOverlay->GetScreenPostion(wEntityHead, sEntityHead); 

				if(!filledCircle)
					ImGui_DrawCircle(sEntityHead, circleRadius, { circleColor[0], circleColor[1], circleColor[2] }, VisualConfig::circleThickness);

				if (filledCircle)
					ImGui_DrawFilledCircle(sEntityHead, circleRadius, { circleColor[0], circleColor[1], circleColor[2], VisualConfig::filledCircleOpacity }); 
			}
		}
	}
}