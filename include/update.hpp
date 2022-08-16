#ifndef UPDATE_H
#define UPDATE_H 

#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"

namespace Update{
    void update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, const char* winnerText);
}

#endif