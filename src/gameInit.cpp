#include "../include/gameInit.hpp"
#include "../include/update.hpp"

// Initialize window
void initWindow() {
    InitWindow(800, 640, "Pong");
    SetWindowPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
    InitAudioDevice();
}

// Initialize game loop
void gameInit () {

    initWindow();

    GameData gameData {};

    //TODO: it seems that the draw function works
    //      but the update function is broke
    //
    //

    while (!WindowShouldClose()) {
        Update::update(&gameData);

        Draw::draw(&gameData);
    }

    CloseWindow();
}
