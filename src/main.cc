#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Necessary for some reason on mac
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "glfwCreateWindow error\n";
        std::cout << glfwGetError(NULL) << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize glad before calling any opengl functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "gladLoadGLLoader error\n";
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 800, 600);


    // Verticies representing a triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Vertex buffer object
    // Used to send large amounts of vertex data to GPU
    unsigned int buffer;
    glGenBuffers(1, &buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
