add_executable(imgui_demo imgui_demo.cc glad.c)

vm_target_dependency(imgui_demo imgui PRIVATE)

target_link_libraries(imgui_demo glfw)
target_link_libraries(imgui_demo dl)
