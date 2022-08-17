#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include <raylib.h>


void gameRules::checkCollision(Ball& ball, Paddle& paddle, Player player) {
    if (CheckCollisionCircleRec(ball.Ball::getCenter(), ball.Ball::getRadius(), paddle.Paddle::getRectangle())) {
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
            game.Game::gameInterrupt(leftPaddle, rightPaddle, winnerText);
        }
        game.Game::reset(ball, leftPaddle, rightPaddle);
    } else if (ball.Ball::getX() < 0) {
        game.Game::addScore(2);
        winnerText = "Player 2 wins~!";
        if (winnerText) {
            game.Game::gameInterrupt(leftPaddle, rightPaddle, winnerText);
        }
        game.Game::reset(ball, leftPaddle, rightPaddle);
    }
}