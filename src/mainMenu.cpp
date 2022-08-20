#include <array>
#include "raylib.h"
#include "../include/MainMenu.hpp"
#include "../include/audio.hpp"

MainMenu::MainMenu () {
}

void MainMenu::menuInput(Audio& audio) {
    //handle wraparound
    if (m_currentSelection > m_menu.size()) {
        m_currentSelection = 0;
    } else if (m_currentSelection < 0) {
        m_currentSelection = m_menu.size();
    }
 
    //handle keypresses
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            audio.Audio::playBallFx();
            m_currentSelection++;
        } else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            audio.Audio::playBallFx();
            m_currentSelection--;
    }
}