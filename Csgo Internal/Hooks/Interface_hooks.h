#pragma once
#include <Interfaces.h>
#include <CUserCmd.h>

using pFnCreateMove = bool(__thiscall*)(void* pthis, float InputSampleTime, CUserCmd* userCmd); 
using pFnDrawModel = void(__thiscall*)(void* pthis, void* result, const DrawModelInfo& info, Matrix_3x4* pBoneToWorld, float* pFlexWeights, float* pFlexDelayedWeights, const Vector3& modelOrigin, int flags); 

extern pFnCreateMove fnCreateMove; 
extern pFnDrawModel fnDrawModel; 

bool __stdcall hCreateMove(float InputSampleTime, CUserCmd* userCmd); 
void __stdcall hDrawModel(void* result, const DrawModelInfo& info, Matrix_3x4* boneToWorld, float* flexWeights, float* flexDelayedWeights, const Vector3& modelOrign, int flags); 
