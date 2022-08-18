#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/audio.hpp"
#include <raylib.h>


void gameRules::checkCollision(Ball& ball, Paddle& paddle, Player player, Audio& audio) {
    if (CheckCollisionCircleRec(ball.Ball::getCenter(), ball.Ball::getRadius(), paddle.Paddle::getRectangle())) {
        audio.Audio::playBallFx();

        if (player == 1) {
            if (ball.Ball::getSpeedX() < 0) {
                ball.Ball::setSpeedX(ball.Ball::getSpeedX() * -1.1);
                ball.Ball::setSpeedY((ball.Ball::getY() - paddle.Paddle::getY()) / (paddle.Paddle::getHeight() / 2) * ball.Ball::getSpeedX() * -1);
            }
        } else if (player == 2) {
            if (ball.Ball::getSpeedX() > 0) {
                ball.Ball::setSpeedX(ball.Ball::getSpeedX() * -1.1);
                ball.Ball::setSpeedY((ball.Ball::getY() - paddle.Paddle::getY()) / (paddle.Paddle::getHeight() / 2) * ball.Ball::getSpeedX() * -1);
            }
        }
    }
}


void gameRules::checkWinner(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, const char* winnerText) {
    if (ball.Ball::getX() > GetScreenWidth()) {
        game.Game::addScore(1);
        winnerText = "Player 1 wins~!";
        if (winnerText) {
            game.Game::gameInterrupt(leftPaddle, rightPaddle, winnerText, BLUE);
        }
        game.Game::reset(ball, leftPaddle, rightPaddle);
    } else if (ball.Ball::getX() < 0) {
        game.Game::addScore(2);
        winnerText = "Player 2 wins~!";
        if (winnerText) {
            game.Game::gameInterrupt(leftPaddle, rightPaddle, winnerText, PINK);
        }
        game.Game::reset(ball, leftPaddle, rightPaddle);
    }
}

void gameRules::checkWinner(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle) {
     if (ball.Ball::getX() > GetScreenWidth()) {
         game.Game::addScore(1);
         game.Game::reset(ball, leftPaddle, rightPaddle);
     } else if (ball.Ball::getX() < 0) {
         game.Game::addScore(2);
         game.Game::reset(ball, leftPaddle, rightPaddle);
     }
 }