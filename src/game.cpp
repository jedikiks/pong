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

void Game::gameInterrupt (Paddle& leftPaddle, Paddle& rightPaddle, const char* text) {
    Game::pause();
    while (Game::isPaused() == true) {
        Game::Draw(leftPaddle, rightPaddle, text);
    
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


//FIXME: need to add refs to parameters
void Game::reset() {
    ball.Ball::reset();
    leftPaddle.Paddle::reset();
    rightPaddle.Paddle::reset();
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

void Game::Draw(Paddle& paddle1, Paddle& paddle2, const char* text){
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