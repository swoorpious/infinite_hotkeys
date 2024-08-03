// Copyright (c) swaroop. All rights reserved.

#ifndef KEYBIND_H
#define KEYBIND_H

struct Keybind
{
    char KEYSTROKE;
    
    bool TRAILING = false; // true for trailing keystrokes
    char TRAILING_KEYSTROKE;
    
    bool CTRL= false;
    bool SHIFT = false;
    bool ALT = false;

    Keybind(char keystroke, bool ctrl, bool shift, bool alt)
    {
        KEYSTROKE = keystroke;
        TRAILING = false;
        CTRL = ctrl;
        SHIFT = shift;
        ALT = alt;
    }
};


#endif //KEYBIND_H
