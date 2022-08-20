#ifndef MAINMENU_H
#define MAINMENU_H

#include "audio.hpp"
#include "raylib.h"
#include <array>

class MainMenu {
    private:
            std::array<const char*, 3> m_menu {"New Game", "Options", "Exit"};
            int m_currentSelection {0};
            Sound m_menuBeep {};

    public:
            MainMenu();

            const char* getCurrentSelection() { return m_menu[m_currentSelection]; }
            int getCurrentSelectionNum() { return m_currentSelection; }
            void defaultSelect() { m_currentSelection = 0; }
            std::array<const char*, 3> getMenu() { return m_menu; }

            void menuInput(Audio& audio);
            void draw();
};

#endif