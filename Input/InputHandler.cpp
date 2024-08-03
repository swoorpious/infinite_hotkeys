#include "InputHandler.h"

InputHandler::InputHandler()
{
    CaptureInputEvents();
}

InputHandler::~InputHandler()
{
    if (hHook)
    {
        UnhookWindowsHookEx(hHook);
    }
}

LRESULT CALLBACK InputHandler::LL_KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0 && wParam == WM_KEYDOWN)
    {
        KBDLLHOOKSTRUCT* pKeyBoard = (KBDLLHOOKSTRUCT*)lParam;
        std::cout << "Key Pressed: " << pKeyBoard->vkCode << std::endl;
    }
    return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

void InputHandler::CaptureInputEvents()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LL_KeyboardProc, hInstance, 0);
    if (!hHook)
    {
        std::cerr << "Failed to install hook!" << std::endl;
    }
}


extern "C" INPUTHANDLER_API InputHandler* CreateInputHandler()
{
    return new InputHandler();
}

extern "C" INPUTHANDLER_API void DestroyInputHandler(InputHandler* pInputHandler)
{
    delete pInputHandler;
}
