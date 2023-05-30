
#include <intrin.h>
#include <D3D9_Hooks.h>

#include <Menu.h>
#include <Visuals.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx9.h>

#include <d3dx9.h>


pFnEndScene fnEndScene = nullptr; 
pFnReset fnReset = nullptr;

HRESULT __stdcall hEndScene(IDirect3DDevice9* hDirect3Ddevice9)
{
	static void* returnAddress = _ReturnAddress(); 

	if (returnAddress == _ReturnAddress())
		return fnEndScene(hDirect3Ddevice9, hDirect3Ddevice9);

	if (!menuInitialized)
		InitializeMenu(hDirect3Ddevice9); 

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	static LPDIRECT3DTEXTURE9 logoTextureID; 
	
	if(!logoTextureID)
		D3DXCreateTextureFromFile(hDirect3Ddevice9, "C:\\Users\\apple\\Downloads\\Internal_Cheat_Logo.png", &logoTextureID);


	ImGui::GetBackgroundDrawList()->AddImage(logoTextureID, { -10, -10}, { 200, 244 });
	
	RenderMenu(); 
	RenderEsp();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return fnEndScene(hDirect3Ddevice9, hDirect3Ddevice9); 
}

HRESULT __stdcall hReset(IDirect3DDevice9* hDirect3Ddevice9, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	ImGui_ImplDX9_CreateDeviceObjects();
	return fnReset(hDirect3Ddevice9, hDirect3Ddevice9, pPresentationParameters);
}

