#include <iostream>
#include <windows.h>

bool __stdcall DllMain(HINSTANCE instance, const DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {

    } else if (reason == DLL_PROCESS_DETACH) {

    }

    return true;
}
