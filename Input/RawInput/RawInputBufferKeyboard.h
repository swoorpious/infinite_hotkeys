// Copyright (c) swaroop. All rights reserved.

// RIM_TYPEKEYBOARD = 1

#ifndef RAWINPUTBUFFERKEYBOARD_H
#define RAWINPUTBUFFERKEYBOARD_H

#include "RawInputBase.h"
#include "../Common/RawInputBufferDeclarations.h"


class RawInputBufferKeyboard : public RawInputBase {
public:
    RawInputBufferKeyboard();

    ~RawInputBufferKeyboard() override = default;

protected:
    static void ProcessRawInput(const RAWKEYBOARD* rawkeyboard);
    void UpdateRawInputData(const RAWINPUT& rawInputData) override;
    
};



#endif //RAWINPUTBUFFERKEYBOARD_H
