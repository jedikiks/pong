#ifndef GAMERULES_H
#define GAMERULES_H

#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"

namespace gameRules{
    void checkCollision(Ball& ball, Paddle& paddle, Player player);
    void checkWinner(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, const char* winnerText);
}

#endif