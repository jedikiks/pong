#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/update.hpp"
#include "../include/ai.hpp"
#include "../include/screenManager.hpp"
#include "../include/audio.hpp"


int main() {
    const char* winnerText {nullptr};

    InitWindow(800, 640, "Pong");
    SetWindowPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
    InitAudioDevice();

    GameScreen currentScreen = START;

    Game game {};

    Audio audio {LoadSound("../resources/audio/coin.wav")};

    Menu mainMenu {std::array<const char*, 2> {"New Game", "Exit"}};
    Menu newGameMenu {std::array<const char*, 2> {"Player vs CPU", "Player vs Player"}};
    
    Ball ball {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 5.0f, 350.0f, 300.0f, WHITE};
    Paddle leftPaddle {20, GetScreenHeight() / 2.0f, 10, 100, 700.0f, BLUE};
    Paddle rightPaddle {GetScreenWidth() - 20.0f, GetScreenHeight() / 2.0f, 10, 100, 700.0f, PINK};

    AI ai {};

    while (!WindowShouldClose()) {
        Update::update(game, ball, leftPaddle, rightPaddle, ai, currentScreen, audio, mainMenu, newGameMenu, winnerText);

        game.Game::Draw(ball, leftPaddle, rightPaddle, currentScreen, mainMenu, newGameMenu);
    }

    CloseWindow();

    return 0;
} 
