#ifndef AI_H
#define AI_H

#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"

class AI {
    private:
            gameDifficulty m_difficulty;
    public:
            AI () {
            }

            void aiMove (Paddle& paddle, Ball& ball);
};
#endif