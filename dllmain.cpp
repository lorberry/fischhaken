#include <iostream>
#include <thread>
#include <windows.h>
#include <MinHook.h>

#pragma comment(lib, "Winmm.lib")

void MainThread(HMODULE instance) {
    PlaySound(TEXT("C:/Windows/Media/Windows Hardware Insert.wav"), nullptr, SND_FILENAME | SND_ASYNC);

    FILE *output_buffer = nullptr;
    AllocConsole();
    freopen_s(&output_buffer, "CONOUT$", "w", stdout);

    while (!GetAsyncKeyState(VK_END)) {
    }

    if (output_buffer) {
        fclose(output_buffer);
    }

    FreeConsole();
    FreeLibraryAndExitThread(instance, 0ul);
}

bool __stdcall DllMain(HINSTANCE instance, const DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        HANDLE thread_handle = CreateThread(nullptr, 0ull, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread),
                                            instance, 0ul, nullptr);

        if (thread_handle && thread_handle != INVALID_HANDLE_VALUE) {
            CloseHandle(thread_handle);
        }
    }

    return true;
}
