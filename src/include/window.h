#ifndef WINDOW_H
#define WINDOW_H

// Include any necessary libraries here
#include <GLFW/glfw3.h>

// Define your class or functions here
GLFWwindow* createWindow(int width, int height, const char* title);
void initGLFW();

#endif // WINDOW_H