#ifndef UPDATE_H
#define UPDATE_H 

#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/ai.hpp"
#include "../include/screenManager.hpp"
#include "../include/audio.hpp"
#include "../include/Menu.hpp"

namespace Update{
    void update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, AI& ai, GameScreen& currentScreen, Audio& audio, Menu& mainMenu, Menu& newGameMenu, const char* winnerText);
}

#endif