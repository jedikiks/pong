#include <array>
#include "raylib.h"
#include "../include/Menu.hpp"
#include "../include/audio.hpp"

Menu::Menu (std::array<const char*, 3> menu3) {
    m_menu3 = menu3;
}

Menu::Menu (std::array<const char*, 2> menu2) {
    m_menu2 = menu2;
}

void Menu::menuInput(Audio& audio) {
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