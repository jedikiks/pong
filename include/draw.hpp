#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"
#include "../include/Menu.hpp"
#include "../include/paddle.hpp"

struct GameData;

struct B_GameData {
    GameData* gameData;
};

namespace Draw {
    void drawBasicWindow(GameData* gameData);
    void draw(GameData* gameData);
    void draw(GameData* gameData, const char* text, Color color);
}

#endif
