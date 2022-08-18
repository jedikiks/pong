#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/update.hpp"
#include "../include/ai.hpp"
#include "../include/screenManager.hpp"


void Update::update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, AI& ai, GameScreen& currentScreen, const char* winnerText) {
    switch(currentScreen) {
        case TITLE: {
            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            ai.AI::aiMove(leftPaddle, ball);
            ai.AI::aiMove(rightPaddle, ball);
            //rightPaddle.Paddle::keyPress(2);

            gameRules::checkCollision(ball, rightPaddle, 2);
            gameRules::checkCollision(ball, leftPaddle, 1);
            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle);

            if (IsKeyPressed(KEY_ENTER)) {
                currentScreen = GAMEPLAY;
                game.Game::reset(ball, leftPaddle, rightPaddle);
            }
        } break;

        case GAMEPLAY: {
            if (IsKeyPressed(KEY_TAB) && game.Game::isPaused() == false) {
                game.Game::gameInterrupt(leftPaddle, rightPaddle, "Paused", YELLOW); 
            }

            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            leftPaddle.Paddle::keyPress(1);
            ai.AI::aiMove(rightPaddle, ball);
            //rightPaddle.Paddle::keyPress(2);

            gameRules::checkCollision(ball, rightPaddle, 2);
            gameRules::checkCollision(ball, leftPaddle, 1);

            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle, winnerText);
        } break;
        default: break;
    }
}   