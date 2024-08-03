cmake_minimum_required(VERSION 3.29)
project(infinite_hotkeys)

set(CMAKE_CXX_STANDARD 23)

# Subdirectories
add_subdirectory(Input)
#    add_subdirectory(Input/Keybind)

#add_subdirectory(Startup)
#add_subdirectory(UI)

# Executable
add_executable(infinite_hotkeys main.cpp)


if (NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
endif ()


if (MSVC)
    # MSVC
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /Zi /DDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /O2 /DNDEBUG")
else ()
    # clang
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -DDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
endif ()


message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")


target_link_libraries(infinite_hotkeys PRIVATE InputHandler)