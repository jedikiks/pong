#ifndef GAME_H
#define GAME_H

#include <string>
#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/draw.hpp"

class Game {
    private:
        bool m_ispaused { false };
        int m_player1_score {}; 
        int m_player2_score {};
    public:
        Game () {};

        void gameInterrupt (GameData* gameData, const char* text, const bool& playSound, Color color);
        bool isPaused();
        void pause();
        void unpause();
        void stopGame();
        void addScore(Player player);
        void matchReset(Ball& ball, Paddle& paddle1, Paddle& paddle2);
        void gameReset(Ball& ball, Paddle& paddle1, Paddle& paddle2);
        void drawPlayerScores();
};
#endif
