cmake_minimum_required(VERSION 3.30)
project(opengl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(glexe main.c)

target_include_directories(glexe PUBLIC ${CMAKE_SOURCE_DIR}/../dependencies)

target_link_libraries(glexe PUBLIC ${CMAKE_SOURCE_DIR}/../dependencies/glfw/libglfw3.a)

if (APPLE)
    target_link_libraries(glexe PUBLIC "-framework Cocoa")
    target_link_libraries(glexe PUBLIC "-framework OpenGL")
    target_link_libraries(glexe PUBLIC "-framework IOKit")
endif()

