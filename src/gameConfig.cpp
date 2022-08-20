#include "raylib.h"
#include "types.hpp"

class GameConfig {
    private:
            Color m_paddle1Color {};
            Color m_paddle2Color {};
            Color m_ballColor {};
            Color m_backgroundColor {};

            enum m_difficulty {EASY, MEDIUM, HARD,};

            KeyboardKey m_player1Up {};
            KeyboardKey m_player1Down {};
            KeyboardKey m_player2Up {};
            KeyboardKey m_player2Down {};

            bool m_soundEnable {};
   public:
            void getRandomColor() {} ;
};