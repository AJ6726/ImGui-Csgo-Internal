#pragma once
#include <Interfaces.h>

#define MAX_PLAYER_NAME_LENGTH		128
#define SIGNED_GUID_LEN				32
#define MAX_CUSTOM_FILES			4	
#define CRC32_t						unsigned __int32

struct PlayerInfo; 

struct IVEngineClient
{
	bool GetPlayerInfo(int entityIndex, PlayerInfo* pinfo)
	{
		return CallVirtualFunction<bool>(this, 8, entityIndex, pinfo); 
	}
	int GetLocalPlayer()
	{
		return CallVirtualFunction<int>(this, 12); 
	}
	void SetViewAngles(Vector3& viewAngles)
	{
		CallVirtualFunction<void, Vector3&>(this, 19, viewAngles); 
	}
	bool IsInGame() 
	{ 
		return CallVirtualFunction<bool>(this, 26);  
	}
	void GetViewAngles(Vector3& viewAngles)
	{
		CallVirtualFunction<void, Vector3&>(this, 18, viewAngles); 
	}
	
};

struct PlayerInfo
{
	__int64			version;
	// network xuid
	__int64			xuid;
	// scoreboard information
	char			name[MAX_PLAYER_NAME_LENGTH];
	// local server user ID, unique while server is running
	int				userID;
	// global unique player identifer
	char			guid[SIGNED_GUID_LEN + 1];
	// friends identification number
	__int32			friendsID;
	// friends name
	char			friendsName[MAX_PLAYER_NAME_LENGTH];
	// true, if player is a bot controlled by game.dll
	bool			fakeplayer;
	// true if player is the HLTV proxy
	bool			ishltv;
	// custom files CRC for this player
	CRC32_t			customFiles[MAX_CUSTOM_FILES];
	// this counter increases each time the server downloaded a new file
	unsigned char	filesDownloaded;
}; 
