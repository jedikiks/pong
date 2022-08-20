#include <array>
#include "raylib.h"
#include "../include/MainMenu.hpp"
#include "../include/audio.hpp"

MainMenu::MainMenu () {
}

void MainMenu::menuInput(Audio& audio) {
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        if (m_currentSelection > 1) {
            m_currentSelection = 0;
        } else {
            m_currentSelection++;
            audio.Audio::playBallFx();
        }
    }

    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            if (m_currentSelection < 1) {
                m_currentSelection = 2;
            } else {
                    audio.Audio::playBallFx();
                    m_currentSelection--;
            }
        }
}