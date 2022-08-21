#include <fstream>
#include <string>
#include "raylib.h"
#include "types.hpp"

#define GET_VARIABLE_NAME(Variable) (#Variable)

class GameConfig {
    private:
            Color m_paddle1Color {};
            Color m_paddle2Color {};
            Color m_ballColor {};
            Color m_backgroundColor {};
            GameDifficulty m_gameDifficulty {};
            KeyboardKey m_player1Up {};
            KeyboardKey m_player1Down {};
            KeyboardKey m_player2Up {};
            KeyboardKey m_player2Down {};
            bool m_soundEnable {};

            // defaults
            Color m_def_paddle1Color {BLUE};
            Color m_def_paddle2Color {PINK};
            Color m_def_ballColor {WHITE};
            Color m_def_backgroundColor {BLACK};
            GameDifficulty m_def_gameDifficulty {HARD};
            KeyboardKey m_def_player1Up {KEY_W};
            KeyboardKey m_def_player1Down {KEY_S};
            KeyboardKey m_def_player2Up {KEY_UP};
            KeyboardKey m_def_player2Down {KEY_DOWN};
            bool m_def_soundEnable {true};

   public:
            void getRandomColor();

            void saveChanges() {
                std::ofstream configWrite { "../config/game.conf" };

               // if no config file is found, make one:
               if (!configWrite) {
                defaultConfig();
               }
                configWrite << GET_VARIABLE_NAME(m_paddle1Color) << '\n';
                configWrite << GET_VARIABLE_NAME(m_paddle2Color) << '\n';
                configWrite << GET_VARIABLE_NAME(m_ballColor) << '\n';
                configWrite << GET_VARIABLE_NAME(m_backgroundColor) << '\n';
                configWrite << GET_VARIABLE_NAME(GameDifficulty GET_VARIABLE_NAME(m_gameDifficulty)) << '\n';
                configWrite << GET_VARIABLE_NAME(KeyboardKey m_player1Up) << '\n';
                configWrite << GET_VARIABLE_NAME(KeyboardKey m_player1Down) << '\n';
                configWrite << GET_VARIABLE_NAME(KeyboardKey m_player2Up) << '\n';
                configWrite << GET_VARIABLE_NAME(KeyboardKey m_player2Down) << '\n';
                configWrite << GET_VARIABLE_NAME(bool m_soundEnable) << '\n';

            }

            void defaultConfig() {
            }
};