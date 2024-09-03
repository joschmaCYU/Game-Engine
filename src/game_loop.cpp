#include <ctime>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "include/window.h"

bool firstFrame = true;

using namespace std;

class KeyToProcess
{
public:
    GLFWwindow* window;
    int key;
    int scancode;
    int action;
    int mods;

    KeyToProcess(GLFWwindow* window, int key, int scancode, int action, int mods);
};

KeyToProcess::KeyToProcess(GLFWwindow* window, int key, int scancode, int action, int mods)
    : window(window), key(key), scancode(scancode), action(action), mods(mods) {}

vector<KeyToProcess> keysToProcess;

void addKeyToProcess(GLFWwindow* window, int key, int scancode, int action, int mods) {
    keysToProcess.push_back(KeyToProcess(window, key, scancode, action, mods));
}

void processInput() {
    // handles any user input that has happened since the last call
    for (int i = 0; i < keysToProcess.size(); i++) {
        KeyToProcess key = keysToProcess[i];
        if (key.key == GLFW_KEY_ESCAPE && key.action == GLFW_PRESS) {
            glfwSetWindowShouldClose(key.window, GLFW_TRUE);
        }
    }
    cout << "Keys to process: " << keysToProcess.size() << endl;
    keysToProcess.clear();
}

void update() {
    // advances the game simulation one step. It runs AI and physics (usually in that order).
}

void render(float delta) {
    // draws the game so the player can see what happened
}

clock_t currentTime = clock();

unsigned int getCurrentTime() {
    return currentTime = clock() - currentTime; 
}

void game_loop(GLFWwindow* window) {
    double previous = getCurrentTime();
    double lag = 0.0;
    const double MS_PER_UPDATE = 16.67; // Assuming 60 FPS

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();

        double current = getCurrentTime();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        processInput();

        while (lag >= MS_PER_UPDATE) {
            update();
            lag -= MS_PER_UPDATE;
        }

        render(lag / MS_PER_UPDATE);
        //cout << "Time: " << current << endl;
    }
}

