#ifndef UPDATE_H
#define UPDATE_H 

#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/ai.hpp"
#include "../include/screenManager.hpp"

namespace Update{
    void update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, AI& ai, GameScreen& currentScreen, const char* winnerText);
}

#endif