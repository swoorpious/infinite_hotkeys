// Copyright (c) swaroop. All rights reserved.

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
        KBDLLHOOKSTRUCT* pKeyBoard = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        printf("Key pressed: %d\n", pKeyBoard->vkCode);
   }
   return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

void InputHandler::CaptureInputEvents()
{
    HINSTANCE hInstance = GetModuleHandle(nullptr);
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LL_KeyboardProc, hInstance, 0);
    if (!hHook)
    {
        std::cerr << "Failed to install hook." << std::endl;
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
