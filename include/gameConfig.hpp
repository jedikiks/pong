#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <fstream>
#include <string>
#include <array>
#include "raylib.h"
#include "../include/types.hpp"

class GameConfig {
    private:
            std::array<unsigned char, 4> m_paddle1ColorArray {};
            std::array<unsigned char, 4> m_paddle2ColorArray {};
            std::array<unsigned char, 4> m_ballColorArray {};
            std::array<unsigned char, 4> m_backgroundColorArray {};

            Color m_paddle1Color {};
            Color m_paddle2Color {};
            Color m_ballColor {};
            Color m_backgroundColor {};

            int m_gameDifficultyValue {};
            GameDifficulty m_gameDifficulty {};

            int m_player1Up {};
            int m_player1Down {};
            int m_player2Up {};
            int m_player2Down {};

            bool m_soundEnable {};

            // defaults
            std::array<unsigned char, 4> m_def_paddle1ColorArray { 0, 121, 241, 255 };
            std::array<unsigned char, 4> m_def_paddle2ColorArray { 255, 109, 194, 255 };
            std::array<unsigned char, 4> m_def_ballColorArray { 255, 255, 255, 255 };
            std::array<unsigned char, 4> m_def_backgroundColorArray { 0, 0, 0, 0 };

            Color m_def_paddle1Color {BLUE};
            Color m_def_paddle2Color {PINK};
            Color m_def_ballColor {WHITE};
            Color m_def_backgroundColor {BLACK};
	    
            GameDifficulty m_def_gameDifficulty {GameDifficulty::HARD};

            int m_def_player1Up {KEY_W};
            int m_def_player1Down {KEY_S};
            int m_def_player2Up {KEY_UP};
            int m_def_player2Down {KEY_DOWN};

            bool m_def_soundEnable {true};

   public:
            GameConfig () {};

            Color getBallColor() { return m_ballColor; }
            Color getleftPaddleColor() { return m_paddle1Color; }
            Color getRightPaddleColor() { return m_paddle2Color; };

	        Color getColorFromArray (std::array<unsigned char, 4> cArr) { return Color { cArr[0], cArr[1], cArr[2], cArr[3] }; } 

            void loadChanges();
            void saveChanges();
            void defaultConfig();
            //void getRandomColor();
};

#endif
