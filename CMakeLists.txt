cmake_minimum_required(VERSION 3.0)
project(imgui)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(IMGUI_BUILD_DEMO "build imgui demo" OFF)

file(GLOB_RECURSE SOURCES src/*.cc src/*.cpp)
add_library(imgui ${SOURCES})

target_include_directories(imgui PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(imgui GL glfw dl)

if (IMGUI_BUILD_DEMO)
  add_subdirectory(demo)
endif()
