// src/include/game_loop.h
#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <GLFW/glfw3.h>

void game_loop(GLFWwindow* window);
void addKeyToProcess(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif // GAME_LOOP_H