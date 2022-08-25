#include "../include/update.hpp"

bool singlePlayer {};

void noPlayerUpdateData(GameData* gameData, bool winBanner) {
    gameData->rightPaddle.Paddle::updateXPosition();
    
    gameData->rightPaddle.Paddle::checkBounds();
    gameData->leftPaddle.Paddle::checkBounds();
    
    gameData->ball.Ball::moveX();
    gameData->ball.Ball::moveY();
    
    gameData->ball.Ball::checkYCollision();

    gameRules::checkCollision(&gameData->ball, &gameData->rightPaddle, 2, &gameData->audio, false);
    gameRules::checkCollision(&gameData->ball, &gameData->leftPaddle, 1, &gameData->audio, false);
    gameRules::checkWinner(gameData, gameData->winnerText, winBanner, 1);
    gameRules::checkWinner(gameData, gameData->winnerText, winBanner, 2);

}

// Update the game data during the demo
void demoUpdateData(GameData* gameData) {
    noPlayerUpdateData(gameData, false);
    gameData->ai.AI::aiMoveDemo(gameData->leftPaddle, gameData->ball, 1);
    gameData->ai.AI::aiMoveDemo(gameData->rightPaddle, gameData->ball, 2);
}

void playerUpdateData(GameData* gameData) {
    if (singlePlayer) {
            gameData->leftPaddle.Paddle::keyPress(1);
            gameData->ai.AI::aiMove(gameData->rightPaddle, gameData->ball);
    } else {
           gameData->leftPaddle.Paddle::keyPress(1);
           gameData->rightPaddle.Paddle::keyPress(2);
    }
}

// The main update function
void Update::update(GameData* gameData) {
        // Updates occur depending on what state we're on 
        switch(gameData->currentScreen) {
            case START: {
                demoUpdateData(gameData);

                if (IsKeyPressed(KEY_ENTER)) {
                    gameData->currentScreen = TITLE;
                    gameData->audio.Audio::playBallFx();
                }

            } break; 
    
            case TITLE: {
                demoUpdateData(gameData);
                
                gameData->mainMenu.Menu::menuInput(gameData->audio);
    
                switch(GetKeyPressed()) {
                    case KEY_BACKSPACE: {
                        gameData->currentScreen = START;
                        gameData->audio.Audio::playBallFx();
                        gameData->mainMenu.Menu::defaultSelect();
                    } break;

                    case KEY_ENTER: {
                        switch(gameData->mainMenu.Menu::getCurrentSelectionNum()) {
                            case(0): {
                                gameData->currentScreen = NEWGAME;
                                gameData->audio.Audio::playBallFx();
                            } break;
                            case(1): {
                                gameData->audio.Audio::playBallFx();
                                EndDrawing();
                                CloseWindow();
                            }break;
                        }
                    } break;
                }
            } break;
    
            case NEWGAME: {
                demoUpdateData(gameData);

                gameData->newGameMenu.Menu::menuInput(gameData->audio);
    
                switch(GetKeyPressed()) {
                    case KEY_BACKSPACE: {
                       gameData->currentScreen = TITLE;
                       gameData->newGameMenu.Menu::defaultSelect();
                    } break;

                    case KEY_ENTER: {
                        switch(gameData->newGameMenu.Menu::getCurrentSelectionNum()) {

                            // for singleplayer
                            case(0): {
                               gameData->currentScreen = GAMEPLAY;
                               singlePlayer = true;
                               gameData->game.Game::gameReset(gameData->ball, gameData->leftPaddle, gameData->rightPaddle);
                            } break;

                            // for multiplayer
                            case(1): {
                                gameData->currentScreen = GAMEPLAY;
                                singlePlayer = false;
                                gameData->game.Game::gameReset(gameData->ball, gameData->leftPaddle, gameData->rightPaddle);

                            } break;
                        }
                    } break;
                }
            } break;
    
            case GAMEPLAY: {
                if (IsKeyPressed(KEY_TAB) && gameData->game.Game::isPaused() == false) {
                    gameData->game.Game::gameInterrupt(gameData, "Paused",  true, YELLOW); 
                }
                noPlayerUpdateData(gameData, true);
                playerUpdateData(gameData);
            } break;
        }
}   
