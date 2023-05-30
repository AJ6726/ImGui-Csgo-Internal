#pragma once
#include <Windows.h>
#include <d3d9.h>

extern HWND gameWindow; 
extern WNDPROC gameWindowProcedure; 
extern IDirect3D9* direct3D9;
extern IDirect3DDevice9* direct3D9_dummyDevice; 

extern void* direct3D9device_vtable; 
extern bool menuInitialized; 

extern void InitializeMenu(IDirect3DDevice9* hDirect3D9device);
extern void GetDirect3D9Device(); 
extern void DestroyMenu(); 
