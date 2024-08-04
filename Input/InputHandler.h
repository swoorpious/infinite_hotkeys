// Copyright (c) swaroop. All rights reserved.
#pragma once

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#ifdef INPUTHANDLER_EXPORTS
#define INPUTHANDLER_API __declspec(dllexport)
#else
#define INPUTHANDLER_API __declspec(dllimport)
#endif

#include <windows.h>
#include <iostream>
#include "RawInput/RawInputBufferKeyboard.h"

class INPUTHANDLER_API InputHandler
{
public:
    InputHandler();
    ~InputHandler();

protected:
    static LRESULT CALLBACK LL_KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
    void CaptureInputEvents();

private:
    HHOOK hHook = nullptr;
    RawInputBufferKeyboard* keyboardInputBuffer;
};

#endif // INPUTHANDLER_H
