#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/update.hpp"


int main() {
    const char* winnerText {nullptr};

    InitWindow(800, 640, "Pong");
    SetWindowPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);
    Game game {};
    Ball ball {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 5.0f, 350.0f, 300.0f, WHITE};
    Paddle leftPaddle {20, GetScreenHeight() / 2.0f, 10, 100, 700.0f, BLUE};
    Paddle rightPaddle {GetScreenWidth() - 20.0f, GetScreenHeight() / 2.0f, 10, 100, 700.0f, PINK};

    while (!WindowShouldClose()) {
        Update::update(game, ball, leftPaddle, rightPaddle, winnerText);
        game.Game::Draw(ball, leftPaddle, rightPaddle);

    }

    CloseWindow();

    return 0;
} 