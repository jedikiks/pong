#ifndef UPDATE_H
#define UPDATE_H 

#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/ai.hpp"

namespace Update{
    void update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, AI& ai, const char* winnerText);
    int getCurrentScreenWidth();
}

#endif