cmake_minimum_required(VERSION 3.10)
project(WinSysInfo)

set(CMAKE_CXX_STANDARD 17)

# Windows SDK configuration
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
endif()

add_executable(WinSysInfo src/main.cpp)
