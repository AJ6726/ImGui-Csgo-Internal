#pragma once
#include <Menu.h>
#include <Menu_Initializer.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx9.h>

HWND gameWindow = nullptr;
WNDPROC gameWindowProcedure = nullptr;
IDirect3D9* direct3D9 = nullptr;
IDirect3DDevice9* direct3D9_dummyDevice = nullptr;

void* direct3D9device_vtable = nullptr;
bool menuInitialized = false;

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND window, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MenuWindowProcedure(HWND window, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);


void InitializeMenu(IDirect3DDevice9* hDirect3D9device);
void GetDirect3D9Device(); 
void DestroyMenu(); 

void InitializeMenu(IDirect3DDevice9* hDirect3D9device)
{
	D3DDEVICE_CREATION_PARAMETERS params = D3DDEVICE_CREATION_PARAMETERS{ };
	hDirect3D9device->GetCreationParameters(&params);
	gameWindow = params.hFocusWindow;

	gameWindowProcedure = reinterpret_cast<WNDPROC>(SetWindowLongPtr(gameWindow, GWLP_WNDPROC, reinterpret_cast<LONG>(MenuWindowProcedure))); 
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	SetupMenuStyle();
	SetupMenuFont();
	ImGui_ImplWin32_Init(gameWindow);
	ImGui_ImplDX9_Init(hDirect3D9device);
	menuInitialized = true; 
}

void GetDirect3D9Device()
{
	EnumWindows(EnumWindowsProc, 0);

	HMODULE d3d9Handle = GetModuleHandle("d3d9.dll");

	using pFnDirect3D9Create9 = IDirect3D9 * (__stdcall*)(UINT SDK_VERSION);
	pFnDirect3D9Create9 fnDirect3D9Create9 = reinterpret_cast<pFnDirect3D9Create9>(GetProcAddress(d3d9Handle, "Direct3DCreate9"));

	direct3D9 = fnDirect3D9Create9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS params = { };
	params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	params.hDeviceWindow = gameWindow;
	params.Windowed = 1;

	direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_NULLREF, gameWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_DISABLE_DRIVER_MANAGEMENT, &params, &direct3D9_dummyDevice);

	direct3D9device_vtable = reinterpret_cast<void*>(direct3D9_dummyDevice);
}


void DestroyMenu()
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	SetWindowLongPtr(gameWindow, GWLP_WNDPROC, reinterpret_cast<LONG>(gameWindowProcedure)); 

	direct3D9->Release();
	direct3D9 = 0;

	direct3D9_dummyDevice->Release();
	direct3D9_dummyDevice = 0;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	DWORD processId = 0; 
	GetWindowThreadProcessId(hwnd, &processId); 
	
	if (GetCurrentProcessId() == processId)
	{
		gameWindow = hwnd; 
		return false; 
	}

	return true; 
}

#include <UConfigs.h>
extern bool showMenu; 
extern bool shoot; 
LRESULT CALLBACK MenuWindowProcedure(HWND window, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (GetAsyncKeyState(VK_INSERT) & 1)
		showMenu = !showMenu; 
	
	if (AimbotConfig::aimbot)
	{
		if (AimbotConfig::mode == AimbotConfig::TOGGLE)
		{
			if (GetAsyncKeyState(AimbotConfig::keyBind) & 1)
				shoot = !shoot; 
		}
		if (AimbotConfig::mode == AimbotConfig::HOLD)
		{
			if (GetAsyncKeyState(AimbotConfig::keyBind))
				shoot = true;
			else
				shoot = false; 
		}
	}

	if (showMenu)
	{
		ImGui_ImplWin32_WndProcHandler(window, uMsg, wParam, lParam);
		return 1; 
	}

	return CallWindowProc(gameWindowProcedure, window, uMsg, wParam, lParam); 
}