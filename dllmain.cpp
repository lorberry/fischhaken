#include <iostream>
#include <thread>
#include <windows.h>

void MainThread(HMODULE instance) {
    while (!GetAsyncKeyState(VK_END)) {
    }

    FreeLibrary(instance);
}

bool __stdcall DllMain(HINSTANCE instance, const DWORD reason, LPVOID reserved) {
    static FILE *p_file{nullptr};
    static std::thread main_thread;

    if (reason == DLL_PROCESS_ATTACH) {
        AllocConsole();
        freopen_s(&p_file, "CONOUT$", "w", stdout);

        main_thread = std::thread([instance] { MainThread(instance); });

        if (main_thread.joinable()) {
            main_thread.detach();
        }
    } else if (reason == DLL_PROCESS_DETACH) {
        fclose(p_file);
        FreeConsole();
    }

    return true;
}
