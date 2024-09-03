#include "include/window.h"
#include "include/game_loop.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <GLFW/glfw3.h>

int main() {
    GLFWwindow* window; // Declare the 'window' variable

    initGLFW();
    window = createWindow(800, 600, "Hello World"); // Assign a value to the 'window' variable

    game_loop(window);

    return 0;
}