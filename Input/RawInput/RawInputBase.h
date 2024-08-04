// Copyright (c) swaroop. All rights reserved.

#ifndef RAWINPUTBASE_H
#define RAWINPUTBASE_H

#include <windows.h>
#include <iostream>



class RawInputBase {
public:
    RawInputBase(const int HW_CODE)
    {
        if (!CreateHiddenWindow())
        {
            std::wcerr << L"Failed to create hidden window. Error: " << GetLastError() << std::endl;
            return;
        }
        if (!RegisterRawInputDevice(HW_CODE))
        {
            std::wcerr << L"Failed to register raw input device. Error: " << GetLastError() << std::endl;
        }
        else
        {
            std::wcout << L"Successfully registered raw input device." << std::endl;
        }
    }

    virtual ~RawInputBase() = default;

    void StartMessageLoop()
    {
        MessageLoop();
    }
    
protected:
    bool RegisterRawInputDevice(const int HW_CODE) const; // callable through derived classes
    virtual void UpdateRawInputData(const RAWINPUT& rawInputData) = 0;

private:
    HWND hwndHidden = nullptr;
    
    bool CreateHiddenWindow();
    void MessageLoop();
};


#endif //RAWINPUTBASE_H
