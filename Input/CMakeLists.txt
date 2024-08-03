add_library(InputHandler SHARED
        InputHandler.cpp
        InputHandler.h
)

target_include_directories(InputHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(InputHandler PRIVATE INPUTHANDLER_EXPORTS)