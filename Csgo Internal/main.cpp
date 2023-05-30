#include <Windows.h>
#include <iostream>
#include <thread>

#include <Menu_Initializer.h>
#include <hooks.h>
#include <Interfaces.h>
#include <UGlobal.h>

FILE* CreateConsole(); 
void DestroyConsole(FILE* file); 

DWORD WINAPI MainThread(HMODULE hModule)
{
    FILE* consoleFile = CreateConsole();
    GetDirect3D9Device(); 
    CreateHooks(); 
    while (true)
    {
        GlobalHelper(); 
        if (GetAsyncKeyState(VK_END) & 1)
        {
            break; 
        }
      
    }

    DestroyHooks(); 
    DestroyMenu(); 
    DestroyConsole(consoleFile); 
    FreeLibraryAndExitThread(hModule, 0); 
}


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    HANDLE hMainThread = nullptr; 

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        hMainThread = CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, 0, 0);
        
        break; 
        
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:

        if (hMainThread)
            CloseHandle(hMainThread);
        
        break;
    }
    return TRUE;
}

FILE* CreateConsole()
{
    AllocConsole();
    FILE* file;
    freopen_s(&file, "CONOUT$", "w", stdout);
    return file;
}
void DestroyConsole(FILE* file)
{
    FreeConsole();
    fclose(file);
}

