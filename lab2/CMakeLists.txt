cmake_minimum_required(VERSION 3.5)

project(lab2 CXX C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME})

# Normal source and header files
file(GLOB proj_sources LIST_DIRECTORIES false CONFIGURE_DEPENDS src/*.cpp src/*.c)
set(proj_include "include")

# Add sources to targe
target_sources(${PROJECT_NAME} PRIVATE "${proj_sources}")
target_include_directories(${PROJECT_NAME} PRIVATE "${proj_include}")

# Find pkg-config packages
find_package(PkgConfig REQUIRED)

