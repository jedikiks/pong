#include "raylib.h"
#include "../include/game.hpp"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/screenManager.hpp"
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


void Game::Draw(Ball& ball, Paddle& paddle1, Paddle& paddle2, GameScreen currentScreen) {
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);
        switch (currentScreen) {
            case TITLE: {
                Game::drawPlayerScores();
                ball.Ball::Draw();
                paddle1.Paddle::Draw();
                paddle2.Paddle::Draw();
                DrawText("Pong", GetScreenWidth() / 2 - MeasureText("Pong", 90) / 2, GetScreenHeight() / 2 - 90, 90, WHITE);
                DrawText("-- Press Enter to Start -- ", GetScreenWidth() / 2 - MeasureText("-- Press Enter to Start --", 20) / 2, GetScreenHeight() / 2 + 10, 20, WHITE);
            } break;
            case GAMEPLAY: {
                Game::drawPlayerScores();
                ball.Ball::Draw();
                paddle1.Paddle::Draw();
                paddle2.Paddle::Draw();
            } break;
            default: break;
        }
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

    DrawText(player1Score, MeasureText(player1Score, 30), 20, 30, BLUE);
    DrawText(player2Score, GetScreenWidth() - MeasureText(player2Score, 30) - 10, 20, 30, PINK);
}