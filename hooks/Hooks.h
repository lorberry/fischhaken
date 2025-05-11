#ifndef HOOKS_H_
#define HOOKS_H_

#include <memory>

#include <MinHook.h>

typedef BOOL (__stdcall*twglSwapBuffers)(HDC hDc);

class Hooks {
public:
    Hooks() {
        MH_Initialize();

        p_swapbuffers = GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers");

        if (p_swapbuffers != nullptr) {
            MH_CreateHook(p_swapbuffers, &wglSwapBuffers, reinterpret_cast<LPVOID *>(&o_swapbuffers));
        }

        MH_EnableHook(MH_ALL_HOOKS);

        init = true;
    }

    void remove() const {
        MH_RemoveHook(p_swapbuffers);
    }

    bool is_init() const {
        return init;
    }

private:
    static bool __stdcall wglSwapBuffers(HDC);

public:
    twglSwapBuffers o_swapbuffers{nullptr};

private:
    bool init{false};

    void *p_swapbuffers;
};

inline std::unique_ptr<Hooks> p_hooks;

#endif
