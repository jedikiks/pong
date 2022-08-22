#include "raylib.h"
#include "../include/ball.hpp"
#include "../include/paddle.hpp"
#include "../include/types.hpp"
#include "../include/game.hpp"
#include "../include/gameRules.hpp"
#include "../include/update.hpp"
#include "../include/ai.hpp"
#include "../include/screenManager.hpp"
#include <array>
#include "../include/Menu.hpp"

bool singlePlayer {};

void Update::update(Game& game, Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, AI& ai, GameScreen& currentScreen, Audio& audio, Menu& mainMenu, Menu& newGameMenu, const char* winnerText) {
    switch(currentScreen) {
        case START: {
            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            ai.AI::aiMoveDemo(leftPaddle, ball, 1);
            ai.AI::aiMoveDemo(rightPaddle, ball, 2);
            //rightPaddle.Paddle::keyPress(2);

            gameRules::checkCollision(ball, rightPaddle, 2);
            gameRules::checkCollision(ball, leftPaddle, 1);
            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle);

            if (IsKeyPressed(KEY_ENTER)) {
                currentScreen = TITLE;
                audio.Audio::playBallFx();
            }
        } break;

        case TITLE: {
            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            ai.AI::aiMoveDemo(leftPaddle, ball, 1);
            ai.AI::aiMoveDemo(rightPaddle, ball, 2);

            gameRules::checkCollision(ball, rightPaddle, 2);
            gameRules::checkCollision(ball, leftPaddle, 1);
            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle);

            mainMenu.Menu::menu3Input(audio);

            switch(GetKeyPressed()) {
                case KEY_BACKSPACE: {
                    currentScreen = START;
                    mainMenu.Menu::defaultSelect();
                    break;
                }
                case KEY_ENTER: {
                    audio.Audio::playBallFx();
                    switch(mainMenu.Menu::getCurrentSelectionNum()) {
                        case(0): {
                            currentScreen = NEWGAME;
                            break;
                        }
                        case(1): {
                                     currentScreen = OPTIONS;
                                     break;
                                 }
                        case(2): {
                            EndDrawing();
                            CloseWindow();
                            break;
                        }
                    }
                }
                default: break; 
            }

        } break;

        case NEWGAME: {
            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            ai.AI::aiMoveDemo(leftPaddle, ball, 1);
            ai.AI::aiMoveDemo(rightPaddle, ball, 2);

            gameRules::checkCollision(ball, rightPaddle, 2);
            gameRules::checkCollision(ball, leftPaddle, 1);
            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle);

            newGameMenu.Menu::menu2Input(audio);

            switch(GetKeyPressed()) {
                case KEY_BACKSPACE: {
                    currentScreen = TITLE;
                    newGameMenu.Menu::defaultSelect();
                    audio.Audio::playBallFx();
                    break;
                }
                case KEY_ENTER: {
                    switch(newGameMenu.Menu::getCurrentSelectionNum()) {
                    audio.Audio::playBallFx();
                        case(0): {
                            currentScreen = GAMEPLAY;
                            singlePlayer = true;

                            game.Game::reset(ball, leftPaddle, rightPaddle);
                            game.Game::resetScores();
                            audio.Audio::playBallFx();

                            break;
                        }
                        case(1): {
                            currentScreen = GAMEPLAY;
                            singlePlayer = false;

                            game.Game::reset(ball, leftPaddle, rightPaddle);
                            game.Game::resetScores();
                            audio.Audio::playBallFx();

                            break;
                        }
                    }
                }
                default: break; 
            }

        } break;

        case OPTIONS: {
            rightPaddle.Paddle::updateXPosition();

            ball.Ball::moveX();
            ball.Ball::moveY();

            ball.Ball::checkYCollision();

            ai.AI::aiMoveDemo(leftPaddle, ball, 1);
            ai.AI::aiMoveDemo(rightPaddle, ball, 2);

            gameRules::checkCollision(ball, rightPaddle, 2);
            gameRules::checkCollision(ball, leftPaddle, 1);
            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle);

            //optionsMenu.Menu::optionsInput(audio);

            switch(GetKeyPressed()) {
                case KEY_BACKSPACE: {
                    currentScreen = TITLE;
                    newGameMenu.Menu::defaultSelect();
                    audio.Audio::playBallFx();
                    break;
                }
                case KEY_ENTER: {
                    switch(newGameMenu.Menu::getCurrentSelectionNum()) {
                    audio.Audio::playBallFx();
                        case(0): {
                            break;
                        }
                        case(1): {

                            break;
                        }
                    }
                }
                default: break; 
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

            switch(singlePlayer) {
                case true: {
                    leftPaddle.Paddle::keyPress(1);
                    ai.AI::aiMove(rightPaddle, ball);
                } break;
                case false: {
                    leftPaddle.Paddle::keyPress(1);
                    rightPaddle.Paddle::keyPress(2);
                }

                default: break;
            }

            gameRules::checkCollision(ball, rightPaddle, 2, audio);
            gameRules::checkCollision(ball, leftPaddle, 1, audio);

            gameRules::checkWinner(game, ball, leftPaddle, rightPaddle, winnerText);
        } break;
        default: break;
    }
}   
