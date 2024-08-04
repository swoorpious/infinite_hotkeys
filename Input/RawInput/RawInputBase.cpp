// Copyright (c) swaroop. All rights reserved.

#include "RawInputBase.h"


bool RawInputBase::RegisterRawInputDevice(const int HW_CODE) const
{
    RAWINPUTDEVICE rid[1];

    rid[0].usUsagePage = 0x01;
    rid[0].usUsage = HW_CODE;
    rid[0].dwFlags = RIDEV_INPUTSINK;
    rid[0].hwndTarget = hwndHidden;

    if (!RegisterRawInputDevices(rid, 1, sizeof(rid[0])))
    {
        MessageBoxW(nullptr, L"Failed to register raw input device.", L"Error", MB_OK);
        return false;
    }

    // printf("Calling MessageLoop()");
    // MessageLoop();
    return true;
}

bool RawInputBase::CreateHiddenWindow()
{
    WNDCLASS wc = {0};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = "RawInputBaseHiddenWindow";

    if (!RegisterClass(&wc))
    {
        return false;
    }

    hwndHidden = CreateWindowExA(
        0,
        wc.lpszClassName,
        "Hidden Window",
        0,
        0, 0, 0, 0,
        HWND_MESSAGE,
        nullptr,
        GetModuleHandle(nullptr),
        nullptr
    );

    return hwndHidden != nullptr;
}

void RawInputBase::MessageLoop()
{
    MSG message;

    while (GetMessage(&message, nullptr, 0, 0))
    {
        if (message.message == WM_INPUT)
        {
            UINT dwSize;
            GetRawInputData(reinterpret_cast<HRAWINPUT>(message.lParam), RID_INPUT, nullptr, &dwSize,
                            sizeof(RAWINPUTHEADER)); // Gets dwSize
            auto lpb = new BYTE[dwSize];


            if (GetRawInputData(reinterpret_cast<HRAWINPUT>(message.lParam), RID_INPUT, lpb, &dwSize,
                                sizeof(RAWINPUTHEADER)) != dwSize) // Uses previously captured dwSize
                OutputDebugString(TEXT("GetRawInputData does not return correct size !\n"));

            auto* raw = reinterpret_cast<RAWINPUT*>(lpb);

            UpdateRawInputData(*raw);

            delete[] lpb;
        }

        TranslateMessage(&message);
        DispatchMessage(&message);
    }
}
