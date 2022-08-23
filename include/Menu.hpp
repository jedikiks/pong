#ifndef MAINMENU_H
#define MAINMENU_H

#include "audio.hpp"
#include "raylib.h"
#include <array>

class Menu {
    private:
            std::array<const char*, 3> m_menu3 {};
            std::array<const char*, 2> m_menu2 {};

            int m_currentSelection {};
            Sound m_menuBeep {};

    public:
            Menu(std::array<const char*, 3> menu3);
            Menu(std::array<const char*, 2> menu2);

            int getCurrentSelectionNum() { return m_currentSelection; }
            void defaultSelect() { m_currentSelection = 0; }

            std::array<const char*, 3> getMenu3() { return m_menu3; }
            const char* getCurrentSelection3() { return m_menu3[m_currentSelection]; }

            std::array<const char*, 2> getMenu2() { return m_menu2; }
            const char* getCurrentSelection2() { return m_menu2[m_currentSelection]; }

            void menuInput(Audio& audio);
            void draw();
};

#endif