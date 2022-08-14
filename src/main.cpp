#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"

void checkCollision(Ball& ball, Paddle& paddle, Player player) {
    if (CheckCollisionCircleRec(ball.Ball::getCenter(), ball.Ball::getRadius(), paddle.Paddle::getRectangle())) {
        if (player == 1) {
            if (ball.Ball::getSpeedX() < 0) {
                ball.Ball::flipDir('x');
            }
        } else if (player == 2) {
            if (ball.Ball::getSpeedX() > 0) {
                ball.Ball::flipDir('x');
            }
        }
    }
}

int main() {
    InitWindow(800, 640, "Pong");
    SetWindowPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);

    Ball ball {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 5.0f, 300.0f, 300.0f, WHITE};
    Paddle leftPaddle {20, GetScreenHeight() / 2.0f, 10, 100, 500, WHITE};
    Paddle rightPaddle {GetScreenWidth() - 20.0f, GetScreenHeight() / 2.0f, 10, 100, 500, WHITE};

    while (!WindowShouldClose()) {
        ball.Ball::setSpeedX(100);
        ball.Ball::setSpeedY(300);

        ball.Ball::isBallInBounds();

        leftPaddle.Paddle::keyPress(1);
        rightPaddle.Paddle::keyPress(2);

        checkCollision(ball, rightPaddle, 2);
        checkCollision(ball, leftPaddle, 1);

        if (ball.Ball::getX() > GetScreenWidth() || ball.Ball::getX() < 0) {
            ball.Ball::reset();
        }


        BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(10, 10);
            SetWindowState(FLAG_VSYNC_HINT);

            ball.Ball::Draw();
            leftPaddle.Paddle::Draw();
            rightPaddle.Paddle::Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}