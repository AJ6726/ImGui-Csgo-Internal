#pragma once

#define BONEMASK 0x7FF00
#define BONE_USED_BY_HITBOX	0x100

struct StudioBone; 
struct StudioHdr; 
struct Model; 

struct IVModelInfo
{
	StudioHdr* GetStudioModel(const Model* model) { return CallVirtualFunction<StudioHdr*, const Model*>(this, 32, model);}
};

struct StudioBone
{
	int					sznameindex;
	int		 			parentBone;
	char pad[152];
	int					flags;
	char pad1[52];
};

struct StudioHdr
{
	int					id;
	int					version;
	int					checkSum;		// this has to be the same in the phy and vtx files to load!
	char				name[64];
	int					length;
	Vector3				eyePosition;	// ideal eye position
	Vector3				illumposition;	// illumination center
	Vector3				hull_min;		// ideal movement hull size
	Vector3				hull_max;
	Vector3				view_bbmin;		// clipping bounding box
	Vector3				view_bbmax;
	int					flags;
	int					numBones;			// bones
	int					boneIndex;
	int					numBoneControllers;
	int					boneControllerIndex;
	int					numHitboxSets;
	int					hitboxSetIndex;
	inline StudioBone* GetBone(int index)
	{
		if (index < 0 || index >= numBones)
			return nullptr;

		return reinterpret_cast<StudioBone*>(reinterpret_cast<unsigned int>(this) + boneIndex) + index;
	}

};

struct Model
{
	void* handle;
	char name[260];
	int loadFlags;
	int serverCount;
	int type;
	int flags;
};
