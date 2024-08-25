#include "window.h"
#include "game_loop.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int main() {

    initGLFW();
    createWindow(800, 600, "Hello World");

    game_loop();

    return 0;
}