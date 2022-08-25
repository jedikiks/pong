#ifndef AI_H
#define AI_H

#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"

class AI {
    public:
            AI () {
            }

            void aiMove (Paddle& paddle, Ball& ball);
            void aiMoveDemo (Paddle& paddle, Ball& ball, Player player);
};
#endif
