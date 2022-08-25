#include "../include/draw.hpp"
#include "../include/gameInit.hpp"

Color getRandomColor() {
    switch(GetRandomValue(0, 1)) {
        case (0): return PINK; break;
        case (1): return BLUE; break;
        //case (2): return GREEN; break;
        default: return BLUE; break;
    }
}

void drawMenuSelectRec(Menu& menu, float heightMod, int selection) {
   Rectangle menuSelectRec { GetScreenWidth() / 2.0f - MeasureText(menu.Menu::getMenu2()[selection], 20.0f) / 2.0f, GetScreenHeight() / 2.0f + heightMod , MeasureText(menu.Menu::getMenu2()[selection], 20.0f) * 1.0f, 10.0f };
   DrawRectangleRec(menuSelectRec, getRandomColor());
    
}

void drawMenuSelect(Menu& menu) {
    switch (menu.Menu::getCurrentSelectionNum()) {
        case 0: {
            drawMenuSelectRec(menu, 60.0f, 0);
        } break;

        case 1: {
            drawMenuSelectRec(menu, 100.0f, 1);
        } break;

        default: break;
    } 
}

// Draws given menu
void buildMenu (Menu& menu, int heightInc) {
    int posCount {};

    for (int i {}; i < menu.Menu::getMenu2().size(); i++) {
        DrawText(menu.Menu::getMenu2()[i], GetScreenWidth() / 2 - MeasureText(menu.Menu::getMenu2()[i], 20) / 2, GetScreenHeight() / 2 + heightInc + posCount, 20, WHITE);
        posCount += 40;
    }

}

void drawGameLayout (GameData* gameData, int pongHeightMod, bool drawTitle) {
    gameData->game.Game::drawPlayerScores();
    gameData->ball.Ball::Draw();
    gameData->leftPaddle.Paddle::Draw();
    gameData->rightPaddle.Paddle::Draw();

    if (drawTitle)
        DrawText("Pong", GetScreenWidth() / 2 - MeasureText("Pong", 90) / 2, GetScreenHeight() / 2 - pongHeightMod, 90, WHITE);
}

void Draw::draw(GameData* gameData) {
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);

        switch (gameData->currentScreen) {
            case START: {
                drawGameLayout(gameData, 90, true);
                DrawText("-- Press Enter to Start -- ", GetScreenWidth() / 2 - MeasureText("-- Press Enter to Start --", 20) / 2, GetScreenHeight() / 2 + 10, 20, WHITE);
            } break;

            case TITLE: {
                drawGameLayout(gameData, 100, true);
                buildMenu(gameData->mainMenu, 40);
                drawMenuSelect(gameData->mainMenu);
            } break;

            case NEWGAME: {
                drawGameLayout(gameData, 100, true);
                buildMenu(gameData->newGameMenu, 40);
                drawMenuSelect(gameData->newGameMenu);
            } break;

            case GAMEPLAY: {
                drawGameLayout(gameData, 100, false);
            } break;

            default: break;
        }
    EndDrawing();
}

void Draw::draw(GameData* gameData, const char* text, Color color){
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);

        gameData->game.Game::drawPlayerScores();
        gameData->leftPaddle.Paddle::Draw();
        gameData->rightPaddle.Paddle::Draw();

        DrawText(text, GetScreenWidth() / 2 - MeasureText(text, 60) / 2, GetScreenHeight() / 2 - 30, 60, color);

    EndDrawing();
}

void Draw::drawBasicWindow(GameData* gameData){
    BeginDrawing();
        ClearBackground(BLACK);
        SetWindowState(FLAG_VSYNC_HINT);
        gameData->game.Game::drawPlayerScores();
    EndDrawing();
}
