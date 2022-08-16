#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/update.hpp"

void Update::update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, const char* winnerText) {
    if (IsKeyDown(KEY_TAB) && game.Game::isPaused() == false) {
        game.Game::pause();
    }
     
    while (game.Game::isPaused() == true) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        SetWindowState(FLAG_VSYNC_HINT);
     
        leftPaddle.Paddle::Draw();
        rightPaddle.Paddle::Draw();
     
        DrawText("Paused", GetScreenWidth() / 2 - MeasureText("Paused", 60) / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
        EndDrawing();
     
        if (IsKeyDown(KEY_ENTER)) {
            game.Game::unpause(); 
        } 
    }
     
    ball.Ball::moveX();
    ball.Ball::moveY();
     
    ball.Ball::checkYCollision();
     
    leftPaddle.Paddle::keyPress(1);
    rightPaddle.Paddle::keyPress(2);
     
    gameRules::checkCollision(ball, rightPaddle, 2);
    gameRules::checkCollision(ball, leftPaddle, 1);
     
    gameRules::checkWinner(game, ball, leftPaddle, rightPaddle, winnerText);
}   