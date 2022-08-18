#ifndef GAMERULES_H
#define GAMERULES_H

#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/audio.hpp"

namespace gameRules{
    void checkCollision(Ball& ball, Paddle& paddle, Player player, Audio& audio);
    void checkWinner(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, const char* winnerText);

//for demo:
    void checkWinner(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle);
}

#endif