cmake_minimum_required(VERSION 3.16)
project(shdnvg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CAMERA REQUIRED libcamera)

add_executable(shdnvg src/main.cpp)

# Link against the libraries
target_link_libraries(shdnvg ${CAMERA_LIBRARIES})
target_include_directories(shdnvg PRIVATE ${CAMERA_INCLUDE_DIRS})