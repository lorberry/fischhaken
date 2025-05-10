#include <iostream>
#include <thread>
#include <windows.h>
#include <MinHook.h>

#include "jvm.h"
#include "sdk/classes/classes.h"
#include "sdk/minecraft/minecraft.h"

#pragma comment(lib, "Winmm.lib")

void MainThread(const HMODULE instance) {
    PlaySound(TEXT("C:/Windows/Media/Windows Hardware Insert.wav"), nullptr, SND_FILENAME | SND_ASYNC);

    FILE *output_buffer = nullptr;
    AllocConsole();
    freopen_s(&output_buffer, "CONOUT$", "w", stdout);

    jvm::load();
    classes::load();

    while (!GetAsyncKeyState(VK_END)) {
        auto minecraft = minecraft::get_minecraft();
        std::cout << "minecraft instance: " << minecraft.cached_object << std::endl;
        auto player = minecraft::get_minecraft().get_local_player();
        std::cout << "player instance: " << player.cached_object << std::endl;


        Sleep(1000);
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
