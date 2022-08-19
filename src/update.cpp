#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/update.hpp"
#include "../include/ai.hpp"
#include "../include/screenManager.hpp"


void Update::update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, AI& ai, GameScreen& currentScreen, Audio& audio, const char* winnerText) {
    switch(currentScreen) {
        case TITLE: {
            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            ai.AI::aiMoveDemo(leftPaddle, ball, 1);
            ai.AI::aiMoveDemo(rightPaddle, ball, 2);
            //rightPaddle.Paddle::keyPress(2);

            gameRules::checkCollision(ball, rightPaddle, 2, audio);
            gameRules::checkCollision(ball, leftPaddle, 1, audio);
            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle);

            if (IsKeyPressed(KEY_ENTER)) {
                currentScreen = GAMEPLAY;
                game.Game::reset(ball, leftPaddle, rightPaddle);
                game.Game::resetScores();
            }
        } break;

        case GAMEPLAY: {
            if (IsKeyPressed(KEY_TAB) && game.Game::isPaused() == false) {
                game.Game::gameInterrupt(leftPaddle, rightPaddle, "Paused", audio, YELLOW); 
            }

            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            leftPaddle.Paddle::keyPress(1);
            ai.AI::aiMove(rightPaddle, ball);
            //rightPaddle.Paddle::keyPress(2);

            gameRules::checkCollision(ball, rightPaddle, 2, audio);
            gameRules::checkCollision(ball, leftPaddle, 1, audio);

            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle, winnerText);
        } break;
        default: break;
    }
}   