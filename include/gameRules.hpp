#ifndef GAMERULES_H
#define GAMERULES_H

#include <string>
#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/audio.hpp"

namespace gameRules{
    void checkCollision(Ball* ball, Paddle* paddle, Player player, Audio* audio, bool playSound);
    void checkWinner(GameData* gameData, const char* winnerText, bool showWinnerBanner, int player);
}

#endif
