#include <ctime>
#include <iostream>

void processInput() {
    // handles any user input that has happened since the last call
    
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

void game_loop() {
    double previous = getCurrentTime();
    double lag = 0.0;
    const double MS_PER_UPDATE = 16.67; // Assuming 60 FPS

    while (true) {
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
        std::cout << "Time: " << current << std::endl;
    }
}

