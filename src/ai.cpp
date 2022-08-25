#include "raylib.h"
#include "../include/ai.hpp"
#include "../include/types.hpp"

void AI::aiMove (Paddle& paddle, Ball& ball) {
    if (paddle.Paddle::getX() != ball.Ball::getX()) {
        if ((paddle.Paddle::getY() + paddle.Paddle::getHeight() / 2) < ball.Ball::getY()) {
            paddle.Paddle::setY(paddle.Paddle::getY() + 700.0f * GetFrameTime());
        } else if ((paddle.Paddle::getY() - paddle.Paddle::getHeight() / 2) >= ball.Ball::getY()){
            paddle.Paddle::setY(paddle.Paddle::getY() - 700.0f * GetFrameTime());
 
        }
    }
}

void AI::aiMoveDemo (Paddle& paddle, Ball& ball, Player player) {
    if (player == 1 && ball.Ball::getX() < (GetScreenWidth() - (GetScreenWidth() / 8.0f))) {
        AI::aiMove(paddle, ball);
    } else if (player == 2 && ball.Ball::getX() > (GetScreenWidth() / 8.0f)) {
        AI::aiMove(paddle, ball);
    }
}
