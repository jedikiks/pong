#include "../include/gameConfig.hpp"
#include <fstream>
#include <ios>
#include <raylib.h>
#include <string>
#include <array>

std::array<unsigned char, 4> getColorArray (unsigned char& red, unsigned char& green, unsigned char& blue) {
    // raylib sets alpha to 255 for each of their colors
    return { red, green, blue, 255 };
}

std::array<unsigned char, 4> myColor = getColorArray('255', 255, 255);
//void GameConfig::getRandomColor();
void GameConfig::defaultConfig() {
    std::ofstream fileWrite { "../config/game.conf" };
    std::string player1Color = "player1Color=" + 
    std::string gameDifficultyDef = "gameDifficulty=" + std::to_string(m_def_gameDifficulty);
    std::string player1UpDef = "player1Up=" + std::to_string(m_def_player1Up);
    std::string player1DownDef = "player1Down=" + std::to_string(m_def_player1Down);
    std::string player2UpDef = "player2Up=" + std::to_string(m_def_player2Up);
    std::string player2DownDef = "player2Down=" + std::to_string(m_def_player2Down);

    fileWrite << gameDifficultyDef << '\n';
    fileWrite << player1UpDef << '\n';
    fileWrite << player1DownDef << '\n';
    fileWrite << player2UpDef << '\n';
    fileWrite << player2DownDef << '\n';

    fileWrite.close();
}

void GameConfig::saveChanges() {
    std::ofstream configWrite { "../config/game.conf", std::ios_base::app };
 
   // if no config file is found, make one:
   if (!configWrite) {
    defaultConfig();
   }
    
   //configWrite << m_paddle1Color;
   //configWrite << m_paddle2Color;
   //configWrite << m_ballColor;
   //configWrite << m_backgroundColor;
   configWrite << m_gameDifficulty << '\n';
   configWrite << m_player1Up << '\n';
   configWrite << m_player1Down << '\n';
   configWrite << m_player2Up << '\n';
   configWrite << m_player2Down << '\n';
   configWrite << m_soundEnable << '\n';

   configWrite.close();
}