cmake_minimum_required(VERSION 3.30)
project(opengl VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(glexe main.cc ../dependencies/glad/src/glad.c)

target_include_directories(glexe PUBLIC ${CMAKE_SOURCE_DIR}/../dependencies)
target_include_directories(glexe PUBLIC ${CMAKE_SOURCE_DIR}/../dependencies/glad/include)

target_link_libraries(glexe PUBLIC ${CMAKE_SOURCE_DIR}/../dependencies/glfw/libglfw3.a)

if (APPLE)
    target_link_libraries(glexe PUBLIC "-framework Cocoa")
    target_link_libraries(glexe PUBLIC "-framework OpenGL")
    target_link_libraries(glexe PUBLIC "-framework IOKit")
endif()

