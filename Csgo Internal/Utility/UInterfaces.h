#pragma once

#include <Windows.h>

template <typename T>
T GetInterfaceClass(const char* interfaceName, const char* libraryName)
{
	HMODULE moduleHandle = GetModuleHandle(libraryName);

	using pFnCreateInterface = T(*)(const char*, int*);
	pFnCreateInterface fnCreateInterface = reinterpret_cast<pFnCreateInterface>(GetProcAddress(moduleHandle, "CreateInterface"));

	return fnCreateInterface(interfaceName, nullptr);
}

template <typename T>
T GetVirtualFunction(void* pthis, int index)
{
	return reinterpret_cast<T>((*reinterpret_cast<void***>(pthis))[index]);
}

template <typename T, typename ... Arguments>
T CallVirtualFunction(void* pthis, int index, Arguments ... args)
{
	using pFunction = T(__thiscall*)(void*, decltype(args)...);
	pFunction Function = GetVirtualFunction<pFunction>(pthis, index);
	return Function(pthis, args...);
}
