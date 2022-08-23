#include "raylib.h"
#include "../include/game.hpp"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/screenManager.hpp"
#include "../include/audio.hpp"
#include <string>
#include "../include/Menu.hpp"

Color getRandomColor() {
    switch(GetRandomValue(0, 1)) {
        case (0): return PINK; break;
        case (1): return BLUE; break;
        //case (2): return GREEN; break;
        default: return BLUE; break;
    }
}

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

void Game::gameInterrupt (Paddle& leftPaddle, Paddle& rightPaddle, const char* text, Audio& audio, Color color) {
    Game::pause();

    int i {0};

    while (Game::isPaused() == true) {
        rightPaddle.Paddle::updateXPosition();
        Game::Draw(leftPaddle, rightPaddle, text, color);

        while (i < 1) {
            audio.Audio::playBallFx();
            WaitTime(0.1f);
            audio.Audio::playBallFx();
            i++;
        }

        //FIXME: ESC quits but produces segmentation fault
        if(WindowShouldClose()) {
            CloseWindow();
        }

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_TAB)) {
            Game::unpause(); 
        } 
    }
}

void Game::gameInterrupt (Paddle& leftPaddle, Paddle& rightPaddle, const char* text, Color color) {
    Game::pause();
    while (Game::isPaused() == true) {
        rightPaddle.Paddle::updateXPosition();
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

void Game::resetScores () {
    m_player1_score = 0;
    m_player2_score = 0;
}

void Game::reset(Ball& ball, Paddle& paddle1, Paddle& paddle2) {
    ball.Ball::reset();
    paddle1.Paddle::reset();
    paddle2.Paddle::reset();
}

void Game::Draw(Ball& ball, Paddle& paddle1, Paddle& paddle2, GameScreen currentScreen, Menu& mainMenu, Menu& newGameMenu) {
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);
        switch (currentScreen) {
            case START: {
                Game::drawPlayerScores();
                ball.Ball::Draw();
                paddle1.Paddle::Draw();
                paddle2.Paddle::Draw();

                DrawText("Pong", GetScreenWidth() / 2 - MeasureText("Pong", 90) / 2, GetScreenHeight() / 2 - 90, 90, WHITE);
                DrawText("-- Press Enter to Start -- ", GetScreenWidth() / 2 - MeasureText("-- Press Enter to Start --", 20) / 2, GetScreenHeight() / 2 + 10, 20, WHITE);
            } break;
            case TITLE: {
                Game::drawPlayerScores();
                ball.Ball::Draw();
                paddle1.Paddle::Draw();
                paddle2.Paddle::Draw();

                int posCount {};
                DrawText("Pong", GetScreenWidth() / 2 - MeasureText("Pong", 90) / 2, GetScreenHeight() / 2 - 100, 90, WHITE);

                for (int i {}; i < mainMenu.Menu::getMenu2().size(); i++) {
                    DrawText(mainMenu.Menu::getMenu2()[i], GetScreenWidth() / 2 - MeasureText(mainMenu.Menu::getMenu2()[i], 20) / 2, GetScreenHeight() / 2 + 40 + posCount, 20, WHITE);
                    posCount += 40;
                }

                switch (mainMenu.Menu::getCurrentSelectionNum()) {
                    case 0: {
                        Rectangle menuSelectRec { GetScreenWidth() / 2.0f - MeasureText(mainMenu.Menu::getMenu2()[0], 20.0f) / 2.0f, GetScreenHeight() / 2.0f + 60.0f , MeasureText(mainMenu.Menu::getMenu2()[0], 20.0f) * 1.0f, 10.0f };
                        DrawRectangleRec(menuSelectRec, getRandomColor());
                    } break;
                    case 1: {
                        Rectangle menuSelectRec { GetScreenWidth() / 2.0f - MeasureText(mainMenu.Menu::getMenu2()[1], 20.0f) / 2.0f, GetScreenHeight() / 2.0f + 100.0f , MeasureText(mainMenu.Menu::getMenu2()[1], 20.0f) * 1.0f, 10.0f };
                        DrawRectangleRec(menuSelectRec, getRandomColor());
                    } break;
                    default: break;
                } 
            } break;

            case NEWGAME: {
                Game::drawPlayerScores();
                ball.Ball::Draw();
                paddle1.Paddle::Draw();
                paddle2.Paddle::Draw();

                int posCount {};
                DrawText("Pong", GetScreenWidth() / 2 - MeasureText("Pong", 90) / 2, GetScreenHeight() / 2 - 100, 90, WHITE);

                for (int i {}; i < newGameMenu.Menu::getMenu2().size(); i++) {
                    DrawText(newGameMenu.Menu::getMenu2()[i], GetScreenWidth() / 2 - MeasureText(newGameMenu.Menu::getMenu2()[i], 20) / 2, GetScreenHeight() / 2 + 40 + posCount, 20, WHITE);
                    posCount += 40;
                }

                switch (newGameMenu.Menu::getCurrentSelectionNum()) {
                    case 0: {
                        Rectangle menuSelectRec { GetScreenWidth() / 2.0f - MeasureText(newGameMenu.Menu::getMenu2()[0], 20.0f) / 2.0f, GetScreenHeight() / 2.0f + 60.0f , MeasureText(newGameMenu.Menu::getMenu2()[0], 20.0f) * 1.0f, 10.0f };
                        DrawRectangleRec(menuSelectRec, getRandomColor());
                    } break;
                    case 1: {
                        Rectangle menuSelectRec { GetScreenWidth() / 2.0f - MeasureText(newGameMenu.Menu::getMenu2()[1], 20.0f) / 2.0f, GetScreenHeight() / 2.0f + 100.0f , MeasureText(newGameMenu.Menu::getMenu2()[1], 20.0f) * 1.0f, 10.0f };
                        DrawRectangleRec(menuSelectRec, getRandomColor());
                    } break;

                default: break;
                }
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
