#include "../include/gameRules.hpp"
#include "../include/gameInit.hpp"

void gameRules::checkCollision(Ball* ball, Paddle* paddle, Player player, Audio* audio, bool playSound) {
    if (CheckCollisionCircleRec(ball->Ball::getCenter(), ball->Ball::getRadius(), paddle->Paddle::getRectangle())) {

        if (playSound) {
            audio->Audio::playBallFx();
        }

        if (player == 1) {
            if (ball->Ball::getSpeedX() < 0) {
                ball->Ball::setSpeedX(ball->Ball::getSpeedX() * -1.1);
                ball->Ball::setSpeedY((ball->Ball::getY() - paddle->Paddle::getY()) / (paddle->Paddle::getHeight() / 2) * ball->Ball::getSpeedX() * -1);
            }
        } else if (player == 2) {
            if (ball->Ball::getSpeedX() > 0) {
                ball->Ball::setSpeedX(ball->Ball::getSpeedX() * -1.1);
                ball->Ball::setSpeedY((ball->Ball::getY() - paddle->Paddle::getY()) / (paddle->Paddle::getHeight() / 2) * ball->Ball::getSpeedX() * -1);
            }
        }
    }
}


void printWinScreen(GameData* gameData, const char* winnerText, const bool& showWinnerBanner, const int& player) {
    gameData->game.Game::addScore(player);

    if (showWinnerBanner) {
        if (player == 1) {
            gameData->winnerText = "Player 1 wins~!";
            if (gameData->winnerText) {
                gameData->game.Game::gameInterrupt(gameData, gameData->winnerText, false, BLUE);
            }
        } else {
            gameData->winnerText = "Player 2 wins~!";
            if (gameData->winnerText) {
                gameData->game.Game::gameInterrupt(gameData, gameData->winnerText, false, PINK);
            }
        gameData->winnerText = {};
    }

    gameData->game.Game::matchReset(gameData->ball, gameData->leftPaddle, gameData->rightPaddle);
    }
}

void gameRules::checkWinner(GameData* gameData, const char* winnerText, bool showWinnerBanner, int player) {

    if (gameData->ball.Ball::getX() > GetScreenWidth()) {
        printWinScreen(gameData, winnerText, showWinnerBanner, 1);
        
    } else if (gameData->ball.Ball::getX() < 0) {
        printWinScreen(gameData, winnerText, showWinnerBanner, 2);
    }
}
