#pragma once
#include <Interfaces.h>
#include <UMatrix.h>

struct CBaseEntity
{
	//Renderable
	const Model* GetModel()			
	{
		return CallVirtualFunction<const Model*>(this + 0x4, 8);
	}

	bool SetupBones(Matrix_3x4* pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime) 
	{ 
		return CallVirtualFunction<bool, Matrix_3x4*, int, int, float>(this + 0x4, 13, pBoneToWorldOut, nMaxBones, boneMask, currentTime);  
	}

	//IClientEnitty 
	Vector3& GetAbsOrigin()	
	{ 
		return CallVirtualFunction<Vector3&>(this, 10); 
	}

	int GetTeam()
	{ 
		return CallVirtualFunction<int>(this, 88);				
	}

	int GetHeatlth()		
	{	
		return CallVirtualFunction<int>(this, 122);	
	}

	bool IsPlayer()							
	{		
		return CallVirtualFunction<bool>(this, 158);	
	}

	Vector3 GetEyePosition()			
	{		
		return CallVirtualFunction<Vector3>(this, 285);		
	}	

	Vector3 GetAimPunch()
	{ 
		Vector3 aimPunch = { 0 }; 
		CallVirtualFunction<void, Vector3&>(this, 346, aimPunch);
		return aimPunch;
	}


};
