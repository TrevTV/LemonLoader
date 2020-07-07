#include <Windows.h>
#include "LemonLoader.h"
#include "ModHandler.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	LemonLoader::thisdll = hinstDLL;
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
#ifndef DEBUG
		DisableThreadLibraryCalls(LemonLoader::thisdll);
#endif
		LemonLoader::Main();
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		LemonLoader::UNLOAD();
		FreeLibrary(LemonLoader::thisdll);
	}
	return TRUE;
}