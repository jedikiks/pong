#ifndef GAMEINIT_H
#define GAMEINIT_H

#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/ai.hpp"
#include "../include/screenManager.hpp"
#include "../include/audio.hpp"

// Struct that holds game objects and variables
struct GameData {
    const char* winnerText {};

    GameScreen currentScreen = START;
    Game game {};
    AI ai {};
    Audio audio {LoadSound("../resources/audio/coin.wav")};
    Menu mainMenu {std::array<const char*, 2> {"New Game", "Exit"}};
    Menu newGameMenu {std::array<const char*, 2> {"Player vs CPU", "Player vs Player"}};
    Ball ball {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 5.0f, 350.0f, 300.0f, WHITE};
    Paddle leftPaddle {20, GetScreenHeight() / 2.0f, 10, 100, 700.0f, BLUE};
    Paddle rightPaddle {GetScreenWidth() - 20.0f, GetScreenHeight() / 2.0f, 10, 100, 700.0f, PINK};
};

void gameInit();

#endif
