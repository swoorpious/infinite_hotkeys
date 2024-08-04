// Copyright (c) swaroop. All rights reserved.

#include "RawInputBufferKeyboard.h"

RawInputBufferKeyboard::RawInputBufferKeyboard() : RawInputBase(RawInputBuffer::HW_KEYBOARD)
{}

void RawInputBufferKeyboard::ProcessRawInput(const RAWKEYBOARD* rawkeyboard)
{
    USHORT keyCode = rawkeyboard->VKey;
    USHORT scanCode = rawkeyboard->MakeCode;
    USHORT flags = rawkeyboard->Flags;

    bool isKeyDown = !(flags & RI_KEY_BREAK);

    printf("Key Code: %d, Scan Code: %d, Flags: %d, Key Down: %d\n", keyCode, scanCode, flags, isKeyDown);
}

void RawInputBufferKeyboard::UpdateRawInputData(const RAWINPUT& rawInputData)
{
    if (rawInputData.header.dwType == RIM_TYPEKEYBOARD)
    {
        const RAWKEYBOARD& rawKeyboardData = rawInputData.data.keyboard;
        ProcessRawInput(&rawKeyboardData);
    }
}



