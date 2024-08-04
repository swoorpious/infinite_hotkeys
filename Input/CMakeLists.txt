add_library(InputHandler SHARED
        InputHandler.cpp
        InputHandler.h
        RawInput/RawInputBufferMouse.cpp
        RawInput/RawInputBufferMouse.h
        RawInput/RawInputBufferKeyboard.cpp
        RawInput/RawInputBufferKeyboard.h
        RawInput/RawInputBase.h
        RawInput/RawInputBase.cpp
)

target_include_directories(InputHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(InputHandler PRIVATE INPUTHANDLER_EXPORTS)