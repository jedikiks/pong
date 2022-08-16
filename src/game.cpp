#include "raylib.h"
#include "../include/game.hpp"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"

Game::Game () {
    m_ispaused = false;
    m_player1_score = 0;
    m_player2_score = 0;
}

void Game::pause () {
        m_ispaused = true;
}

void Game::unpause () {
        m_ispaused = false;
}

bool Game::isPaused() {
    if (m_ispaused == true) {
        return true;
    } else {
        return false;
    }
}

void Game::addScore (Player player) {
    if (player == 1) {
        m_player1_score++;
    } else {
        m_player2_score++;
    }
}

void Game::subScore (Player player) {
    if (player == 1) {
        m_player1_score--;
    } else {
        m_player2_score--;
    }
}


void Game::resetScores () {
    m_player1_score = 0;
    m_player2_score = 0;
}


void Game::Draw(Ball& ball, Paddle& paddle1, Paddle& paddle2) {
    BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        SetWindowState(FLAG_VSYNC_HINT);
    
        ball.Ball::Draw();
        paddle1.Paddle::Draw();
        paddle2.Paddle::Draw();
    EndDrawing();
}

void Game::winDraw(Paddle& paddle1, Paddle& paddle2, const char* text){
    BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        SetWindowState(FLAG_VSYNC_HINT);

        DrawText(text, GetScreenWidth() / 2 - MeasureText(text, 60) / 2, GetScreenHeight() / 2 - 30, 60, YELLOW);
        paddle1.Paddle::Draw();
        paddle2.Paddle::Draw();
    EndDrawing();
}

void Game::Draw(){
    BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        SetWindowState(FLAG_VSYNC_HINT);
    EndDrawing();
}