#include "raylib.h"
#include "../include/game.hpp"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include <string>

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

void Game::gameInterrupt (Paddle& leftPaddle, Paddle& rightPaddle, const char* text, Color color) {
    Game::pause();
    while (Game::isPaused() == true) {
        Game::Draw(leftPaddle, rightPaddle, text, color);
    
        //FIXME: ESC quits but produces segmentation fault
        if(WindowShouldClose()) {
            CloseWindow();
        }

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_TAB)) {
            Game::unpause(); 
        } 
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

void Game::reset(Ball& ball, Paddle& paddle1, Paddle& paddle2) {
    ball.Ball::reset();
    paddle1.Paddle::reset();
    paddle2.Paddle::reset();
}


void Game::Draw(Ball& ball, Paddle& paddle1, Paddle& paddle2) {
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);
        Game::drawPlayerScores();

        ball.Ball::Draw();
        paddle1.Paddle::Draw();
        paddle2.Paddle::Draw();
    EndDrawing();
}

void Game::Draw(Paddle& paddle1, Paddle& paddle2, const char* text, Color color){
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);
        Game::drawPlayerScores();

        DrawText(text, GetScreenWidth() / 2 - MeasureText(text, 60) / 2, GetScreenHeight() / 2 - 30, 60, color);
        paddle1.Paddle::Draw();
        paddle2.Paddle::Draw();
    EndDrawing();
}

void Game::Draw(){
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);
        Game::drawPlayerScores();
    EndDrawing();
}

void Game::drawPlayerScores() {
    std::string p1s { std::to_string(m_player1_score) };
    std::string p2s { std::to_string(m_player2_score) };
    const char* player1Score = p1s.c_str();
    const char* player2Score = p2s.c_str();

    DrawText(player1Score, 10, 10, 30, BLUE);
    DrawText(player2Score, GetScreenWidth() - 20, 10, 30, PINK);
}