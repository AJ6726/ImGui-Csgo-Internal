
#include <Menu_Initializer.h>

using pFnEndScene = HRESULT(__thiscall*)(void*, IDirect3DDevice9*);
using pFnReset = HRESULT(__thiscall*)(void*, IDirect3DDevice9*, D3DPRESENT_PARAMETERS* pPresentationParameters);

extern pFnEndScene fnEndScene;
extern pFnReset fnReset;

HRESULT __stdcall hEndScene(IDirect3DDevice9* hDirect3Ddevice9);
HRESULT __stdcall hReset(IDirect3DDevice9* hDirect3Ddevice9, D3DPRESENT_PARAMETERS* pPresentationParameters);
