#include "../include/game.hpp"
#include "../include/gameInit.hpp"

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

// Stops drawing and closes the window
void Game::stopGame() {
   if(WindowShouldClose()) {
       EndDrawing();
       CloseWindow();
   }
}

// For pausing the game
// Plays a beep if playSound is set to true
void Game::gameInterrupt (GameData* gameData, const char* text, const bool& playSound, Color color) {
    Game::pause();

    bool hasBeeped {false};
    while (Game::isPaused() == true) {
        gameData->rightPaddle.Paddle::updateXPosition();
        Draw::draw(gameData, text, color);

        if (playSound == true) {
            while (!hasBeeped) {
                gameData->audio.Audio::playBallFx();
                WaitTime(0.1f);
                gameData->audio.Audio::playBallFx();
                hasBeeped = true;
            }
        }
            
        //FIXME: ESC quits but produces segmentation fault
        Game::stopGame();

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

void Game::matchReset(Ball& ball, Paddle& paddle1, Paddle& paddle2) {
    ball.Ball::reset();
    paddle1.Paddle::reset();
    paddle2.Paddle::reset();
}
void Game::gameReset(Ball& ball, Paddle& paddle1, Paddle& paddle2) {
    Game::matchReset(ball, paddle1, paddle2);
    m_player1_score = 0;
    m_player2_score = 0;
}

void Game::drawPlayerScores() {
    std::string p1s { std::to_string(m_player1_score) };
    std::string p2s { std::to_string(m_player2_score) };
    const char* player1Score = p1s.c_str();
    const char* player2Score = p2s.c_str();

    DrawText(player1Score, MeasureText(player1Score, 30), 20, 30, BLUE);
    DrawText(player2Score, GetScreenWidth() - MeasureText(player2Score, 30) - 10, 20, 30, PINK);
}
