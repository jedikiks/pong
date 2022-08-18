#include "raylib.h"
#include "../include/ai.hpp"
#include "types.hpp"


void AI::aiMove (Paddle& paddle, Ball& ball) {
    if (paddle.Paddle::getX() != ball.Ball::getX()) {
        if ((paddle.Paddle::getY() + paddle.Paddle::getHeight() / 2) < ball.Ball::getY()) {
            paddle.Paddle::setY(paddle.Paddle::getY() + 700.0f * GetFrameTime());
        } else if ((paddle.Paddle::getY() - paddle.Paddle::getHeight() / 2) >= ball.Ball::getY()){
            paddle.Paddle::setY(paddle.Paddle::getY() - 700.0f * GetFrameTime());
 
        }
    }
}