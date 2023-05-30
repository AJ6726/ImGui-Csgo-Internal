#pragma once

namespace MenuConfig
{
	inline int option = 0;
	inline int aim = 1; 
	inline int visuals = 2; 
	inline int misc = 3; 
}

namespace AimbotConfig
{
	enum ActivateMode : int
	{
		TOGGLE = 0, 
		HOLD
	};
	inline bool aimbot = false; 
	inline char keyBind; 
	inline int mode = 0; 
	inline float Ysmoothness = 25.f; 
	inline float Xsmoothness = 25.f; 
}
namespace RecoilConfig
{
	inline bool recoilControl = false; 
}
namespace TriggerConfig
{
	inline bool triggerbot = false; 
}

namespace VisualConfig
{
	inline bool playerChams = false; 
	inline bool playerWireFrame = false;

	inline bool enemyBox = false;
	inline bool enemyCornerBox = false;
		
	inline bool enemySkeleton = false; 

	inline bool enemyTracelines = false;

	inline bool enemyHealthbar = false;

	inline bool enemyNames = false; 
	inline bool enemyHeadCircle = false; 
	inline bool enemyFilledHeadCircle = false; 

	inline bool enemyChams = false; 
	inline bool enemyWireFrame = false; 

	inline bool teamBox = false;
	inline bool teamCornerBox = false;

	inline bool teamSkeleton = false; 

	inline bool teamTracelines = false;

	inline bool teamNames = false; 
	inline bool teamHeadCircle = false;
	inline bool teamFilledHeadCircle = false; 

	inline bool teamHealthbar = false;

	inline bool teamChams = false; 
	inline bool teamWireFrame = false; 

	inline float enemyColor[3] = { 255.f, 255.f, 255.f };
	inline float teamColor[3] = { 255.f, 255.f, 255.f };

	inline float boxThickness = 1.f;
	inline int boxRounding = 0;

	inline float skeletonThickness = 1.f;

	inline float circleThickness = 1.f; 
	inline float filledCircleOpacity = 1.f; 

	inline float tracelineThickness = 1.f;
	inline int tracelineTarget = 0;
	inline int tracelineOrigin = 0;

	inline int healthbarLocation = 0;
	inline float headCircleThickness = 1.f; 
	
	inline float cornerBoxThickness = 1.f;
	inline float cornerBox_sideSpace = 2.f;
	inline float cornerBox_topbottomSpace = 2.f;

	inline float chamsHiddenColor[3] = { 255.f, 255.f, 255.f };
	inline int modelMaterial = 0;
	inline float chamsOpacitiy = 1.f;
	inline float chamsVisibleColor[3] = { 255.f, 200.f, 255.f };
};

namespace MiscConfig
{
	inline bool bHop = false; 
}