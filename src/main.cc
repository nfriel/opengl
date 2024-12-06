#define GL_SILENCE_DEPRECATION

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include <iostream>

int main(void)
{
    glfwInit();

    // Versions of OpenGL required (or is it versions of GLFW?)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Necessary on mac
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Prevent window resizing
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(600, 400, "OpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "glfwCreateWindow error\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout <<"gladLoadGLLoader error\n";
        glfwTerminate();
        return -1;
    }

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
