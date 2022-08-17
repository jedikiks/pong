#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/update.hpp"


void Update::update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, const char* winnerText) {

    if (IsKeyPressed(KEY_TAB) && game.Game::isPaused() == false) {
        game.Game::gameInterrupt(leftPaddle, rightPaddle, "Paused", YELLOW); 
    }

    ball.Ball::moveX();
    ball.Ball::moveY();
     
    ball.Ball::checkYCollision();
     
    leftPaddle.Paddle::keyPress(1);
    rightPaddle.Paddle::keyPress(2);
     
    gameRules::checkCollision(ball, rightPaddle, 2);
    gameRules::checkCollision(ball, leftPaddle, 1);
     
    gameRules::checkWinner(game, ball, leftPaddle, rightPaddle, winnerText);
}   