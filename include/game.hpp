#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "../include/types.hpp"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "screenManager.hpp"

class Game {
    private:
        bool m_ispaused { false };
        int m_player1_score {}; 
        int m_player2_score {};
    public:
        Game ();

        void gameInterrupt (Paddle& leftPaddle, Paddle& rightPaddle, const char* text, Color color);
        bool isPaused();
        void pause();
        void unpause();
        void addScore(Player player);
        void subScore(Player player);
        void resetScores();
        void Draw(Ball& ball, Paddle& paddle1, Paddle& paddle2, GameScreen currentScreen);
        void Draw(Paddle& paddle1, Paddle& paddle2, const char* text, Color color);
        void Draw();
        void drawPlayerScores();
        void reset(Ball& ball, Paddle& paddle1, Paddle& paddle2);
};
#endif