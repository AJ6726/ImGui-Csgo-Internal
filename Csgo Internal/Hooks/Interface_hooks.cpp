#include <Interface_hooks.h>
#include <Interfaces.h> 
#include <UConfigs.h>
#include <UGlobal.h>

extern void Triggerbot(CBaseEntity* localPlayer, CUserCmd* userCmd); 
extern void Aimbot(); 
extern void BHop(CUserCmd* userCmd); 

pFnCreateMove fnCreateMove = nullptr; 
pFnDrawModel fnDrawModel = nullptr; 

bool __stdcall hCreateMove(float InputSampleTime, CUserCmd* userCmd)
{
	bool result = fnCreateMove(Interfaces::ClientModeShared, InputSampleTime, userCmd); 

	if (!userCmd || !userCmd->commandNumber)
		return result; 

	if (Global::localPlayer)
	{
		if (AimbotConfig::aimbot)
			Aimbot(); 

		if (TriggerConfig::triggerbot)
			Triggerbot(Global::localPlayer, userCmd); 

		if (MiscConfig::bHop)
			BHop(userCmd); 
	}
	return false; 
}

void __stdcall hDrawModel(void* result, const DrawModelInfo& info, Matrix_3x4* boneToWorld, float* flexWeights, float* flexDelayedWeights, const Vector3& modelOrign, int flags)
{
	if (Global::localPlayer && Interfaces::engineClient->IsInGame() && info.clientRenderable)
	{
		CBaseEntity* entity = info.clientRenderable->GetIClientUnkown()->GetBaseEntity(); 

		IMaterial* chamMaterial = Interfaces::materialSystem->FindMaterial("debug/debugambientcube");

		if (entity && entity->IsPlayer() && entity != Global::localPlayer)
		{
			if (VisualConfig::enemyChams)
			{
				if (entity->GetTeam() != Global::localPlayer->GetTeam())
				{
					chamMaterial->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, VisualConfig::enemyWireFrame);

					chamMaterial->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, true);
					Interfaces::studioRenderer->SetColorModulation(VisualConfig::chamsHiddenColor);
					Interfaces::studioRenderer->SetAlphaModulation(VisualConfig::chamsOpacitiy);
					Interfaces::studioRenderer->ForcedMaterialOverride(chamMaterial);
					fnDrawModel(Interfaces::studioRenderer, result, info, boneToWorld, flexWeights, flexDelayedWeights, modelOrign, flags);

					chamMaterial->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
					Interfaces::studioRenderer->SetColorModulation(VisualConfig::chamsVisibleColor);
					Interfaces::studioRenderer->SetAlphaModulation(VisualConfig::chamsOpacitiy);
					Interfaces::studioRenderer->ForcedMaterialOverride(chamMaterial);
					fnDrawModel(Interfaces::studioRenderer, result, info, boneToWorld, flexWeights, flexDelayedWeights, modelOrign, flags);
				}

			}

			if(!VisualConfig::enemyChams && !VisualConfig::teamChams || VisualConfig::teamChams)
				fnDrawModel(Interfaces::studioRenderer, result, info, boneToWorld, flexWeights, flexDelayedWeights, modelOrign, flags);

			return Interfaces::studioRenderer->ForcedMaterialOverride(nullptr);
		}

		if (VisualConfig::playerChams)
		{
			chamMaterial->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, VisualConfig::playerWireFrame); 
			chamMaterial->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, false);
			Interfaces::studioRenderer->SetColorModulation(VisualConfig::chamsVisibleColor);
			Interfaces::studioRenderer->SetAlphaModulation(VisualConfig::chamsOpacitiy);
			Interfaces::studioRenderer->ForcedMaterialOverride(chamMaterial);
			fnDrawModel(Interfaces::studioRenderer, result, info, boneToWorld, flexWeights, flexDelayedWeights, modelOrign, flags);

			return Interfaces::studioRenderer->ForcedMaterialOverride(nullptr);
		}
	}
	fnDrawModel(Interfaces::studioRenderer, result, info, boneToWorld, flexWeights, flexDelayedWeights, modelOrign, flags);
}