cmake_minimum_required(VERSION 3.16)
project(shdnvg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# dependencies for shdnvg
find_package(libcamera REQUIRED)

add_executable(shdnvg
    src/main.cpp
)