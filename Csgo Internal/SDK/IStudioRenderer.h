#pragma once
#include <Interfaces.h>

struct DrawModelInfo; 

enum OverrideType : int
{
	OVERRIDE_NORMAL = 0,
	OVERRIDE_BUILD_SHADOWS,
	OVERRIDE_DEPTH_WRITE,
	OVERRIDE_SELECTIVE,
	OVERRIDE_SSAO_DEPTH_WRITE,
};

struct IStudioRenderer
{
	void SetColorModulation(const float* color) { CallVirtualFunction<void, const float*>(this, 27, color); }
	void SetAlphaModulation(float alpha) { CallVirtualFunction<void, float>(this, 28, alpha);  }
	void ForcedMaterialOverride(IMaterial* newMaterial, OverrideType overrideType = OVERRIDE_NORMAL, int materialIndex = -1) 
	{
		return CallVirtualFunction<void, IMaterial*, OverrideType, int>(this, 33, newMaterial, overrideType, materialIndex);
	}
};

struct DrawModelInfo
{
	StudioHdr*		studioHdr;
	void*			m_pHardwareData;
	int				m_Decals;
	int				m_Skin;
	int				m_Body;
	int				m_HitboxSet;
	IClientRenderable* clientRenderable;
	int				m_Lod;
	void*			m_pColorMeshes;
	bool			m_bStaticLighting;
};
