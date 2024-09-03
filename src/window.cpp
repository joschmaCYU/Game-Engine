#include <GLFW/glfw3.h>
#include <cstdio>
#include <cstdlib> 
#include "window.h"
#include "game_loop.h"
#include <iostream>

void initGLFW() {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
}

void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    addKeyToProcess(window, key, scancode, action, mods);
    std::cout << "Key: " << key << std::endl;
}

GLFWwindow* createWindow(int width, int height, const char* title) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    /*while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }*/
   return window;
}