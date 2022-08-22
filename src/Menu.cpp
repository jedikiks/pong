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

void Menu::menu3Input(Audio& audio) {
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        if (m_currentSelection > 1) {
            m_currentSelection = 0;
            audio.Audio::playBallFx();
        } else {
            m_currentSelection++;
            audio.Audio::playBallFx();
        }
    }

    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            if (m_currentSelection < 1) {
                m_currentSelection = 2;
                audio.Audio::playBallFx();
            } else {
                audio.Audio::playBallFx();
                m_currentSelection--;
            }
        }
}

void Menu::menu2Input(Audio& audio) {
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
        if (m_currentSelection > 0) {
            m_currentSelection = 0;
            audio.Audio::playBallFx();
        } else {
            m_currentSelection++;
            audio.Audio::playBallFx();
        }
    }

    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            if (m_currentSelection < 1) {
                m_currentSelection = 1;
                audio.Audio::playBallFx();
            } else {
                audio.Audio::playBallFx();
                m_currentSelection--;
            }
        }
}

//void Menu::optionsInput(Audio& audio) {
//}
