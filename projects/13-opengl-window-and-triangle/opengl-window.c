#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

void safe_exit() {
    glfwTerminate();
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void initialize_glfw()
{
    glfwSetErrorCallback(error_callback);
}

void create_window()
{
    GLFWwindow* window = glfwCreateWindow(640, 480, "My window", NULL, NULL);
    if(!window)
    {
        fprintf(stderr, "Window failed to be created");
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
}

int main(void) {
    initialize_glfw();
    if(!glfwInit())
    {
        fprintf(stderr, "GLFW init failed");
    }
    while(1)
    {
        create_window();
    }
    safe_exit();
    return 1;
}
