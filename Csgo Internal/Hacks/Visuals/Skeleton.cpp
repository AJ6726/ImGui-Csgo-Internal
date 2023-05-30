#include <Interfaces.h>
#include <ImGui_Wrappers.h>
#include <UConfigs.h>

void DrawSkeleton (CBaseEntity* entity, float skeletonColor[3])
{
	StudioHdr* hdr = Interfaces::modelInfo->GetStudioModel(entity->GetModel());

	Matrix_3x4 entityBones[128];
	if (entity->SetupBones(entityBones, 128, BONEMASK, Interfaces::globalVars->currentTime))
	{
		for (int i = 0; i < hdr->numBones; i++)
		{
			if (i == 8)
				continue;

			StudioBone* bone = hdr->GetBone(i);

			if (bone && bone->flags & BONE_USED_BY_HITBOX && bone->parentBone != -1)
			{
				Vector3 wBone = entityBones[i].Get3DPosition();
				Vector3 wParentBone = entityBones[bone->parentBone].Get3DPosition();

				Vector2 sBone;
				Vector2 sParentbone;
				if (!Interfaces::debugOverlay->GetScreenPostion(wBone, sBone) && !Interfaces::debugOverlay->GetScreenPostion(wParentBone, sParentbone))
				{
					ImGui_DrawLine(sBone, sParentbone, skeletonColor, VisualConfig::skeletonThickness);
				}
			}
		}
	}
}
