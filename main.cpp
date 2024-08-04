#include <windows.h>
#include <iostream>

typedef void (*CreateInputHandlerFunc)();
typedef void (*DestroyInputHandlerFunc)();

int main()
{
    HMODULE hMod = LoadLibraryW(L"Input/InputHandler.dll"); // Use LoadLibraryW for Unicode
    if (!hMod)
    {
        std::cerr << "Failed to load DLL!" << std::endl;
        return 1;
    }


    auto CreateInputHandler = reinterpret_cast<CreateInputHandlerFunc>(GetProcAddress(hMod, "CreateInputHandler"));
    auto DestroyInputHandler = reinterpret_cast<DestroyInputHandlerFunc>(GetProcAddress(hMod, "DestroyInputHandler"));

    if (!CreateInputHandler || !DestroyInputHandler)
    {
        std::cerr << "Failed to get function addresses!" << std::endl;
        FreeLibrary(hMod);
        return 1;
    }

    // InputHandler.dll
    CreateInputHandler();
    
    return 0;
}
