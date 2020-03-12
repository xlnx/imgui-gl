cmake_minimum_required(VERSION 3.0)
project(imgui)
set(CMAKE_CXX_STANDARD 14)

find_package(Git)
execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive)
# install external modules
include(scripts/external.cmake)

option(IMGUI_BUILD_DEMO "build imgui demo" OFF)

file(GLOB_RECURSE SOURCES src/*.cc src/*.cpp)
add_library(imgui ${SOURCES})

target_include_directories(imgui PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(imgui GL)

if (IMGUI_BUILD_DEMO)
  add_subdirectory(demo)
endif()
