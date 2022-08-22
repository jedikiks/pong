#include "../include/gameConfig.hpp"
#include "types.hpp"
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <raylib.h>

void writeArray (std::ofstream& file, std::array<unsigned char, 4>& array) {
	for (const auto& element: array) {
		file << element << '\n';	
	}
}

void GameConfig::defaultConfig() {

    m_paddle1Color = m_def_paddle1Color;
    m_paddle2Color = m_def_paddle2Color;
    m_ballColor = m_def_ballColor;
    m_backgroundColor = m_def_backgroundColor;
    m_gameDifficulty = m_def_gameDifficulty;
    m_player1Up = m_def_player1Up;
    m_player1Down = m_def_player1Down;
    m_player2Up = m_def_player2Up;
    m_player2Down = m_def_player2Down;



    //std::ofstream fileWrite { "../config/game.conf" };

    //        writeArray(fileWrite, m_def_paddle1ColorArray);
    //        writeArray(fileWrite, m_def_paddle2ColorArray);
    //        writeArray(fileWrite, m_def_ballColorArray);
    //        writeArray(fileWrite, m_def_backgroundColorArray);

    //        fileWrite << m_def_gameDifficulty << '\n';
    //        fileWrite << m_def_player1Up << '\n';
    //        fileWrite << m_def_player1Down << '\n';
    //        fileWrite << m_def_player2Up << '\n';
    //        fileWrite << m_def_player2Down << '\n';
    //        fileWrite << m_def_soundEnable << '\n';
}

void GameConfig::saveChanges() {
   std::ofstream configWrite { "../config/game.conf" };
 
   writeArray(configWrite, m_paddle1ColorArray);
   writeArray(configWrite, m_paddle2ColorArray);
   writeArray(configWrite, m_ballColorArray);
   writeArray(configWrite, m_backgroundColorArray);

   configWrite << static_cast<int>(m_gameDifficulty) << '\n';
   configWrite << (m_player1Up) << '\n';
   configWrite << m_player1Down << '\n';
   configWrite << m_player2Up << '\n';
   configWrite << m_player2Down << '\n';
   configWrite << m_soundEnable << '\n';

   configWrite.close();
}

void GameConfig::loadChanges() {
   std::ifstream configLoad { "../config/game.conf" };
    
   if (!configLoad) {
       defaultConfig();
   }

   configLoad >> m_paddle1ColorArray[0];
   configLoad >> m_paddle1ColorArray[1];
   configLoad >> m_paddle1ColorArray[2];
   configLoad >> m_paddle1ColorArray[3];
   configLoad >> m_paddle2ColorArray[0];
   configLoad >> m_paddle2ColorArray[1];
   configLoad >> m_paddle2ColorArray[2];
   configLoad >> m_paddle2ColorArray[3];
   configLoad >> m_ballColorArray[0];
   configLoad >> m_ballColorArray[1];
   configLoad >> m_ballColorArray[2];
   configLoad >> m_ballColorArray[3];
   configLoad >> m_backgroundColorArray[0];
   configLoad >> m_backgroundColorArray[1];
   configLoad >> m_backgroundColorArray[2];
   configLoad >> m_backgroundColorArray[3];

   configLoad >> m_gameDifficultyValue;
   configLoad >> m_player1Up;
   configLoad >> m_player1Down;
   configLoad >> m_player2Up;
   configLoad >> m_player2Down;
   configLoad >> m_soundEnable;

   configLoad.close();

   m_gameDifficulty = static_cast<GameDifficulty>(m_gameDifficultyValue);
}
    


//void GameConfig::getRandomColor();
//
//void GameConfig::defaultConfig() {
    //std::ofstream fileWrite { "../config/game.conf" };
    //std::string player1Color = "player1Color=" + 
    //std::string gameDifficultyDef = "gameDifficulty=" + std::to_string(m_def_gameDifficulty);
    //std::string player1UpDef = "player1Up=" + std::to_string(m_def_player1Up);
    //std::string player1DownDef = "player1Down=" + std::to_string(m_def_player1Down);
    //std::string player2UpDef = "player2Up=" + std::to_string(m_def_player2Up);
    //std::string player2DownDef = "player2Down=" + std::to_string(m_def_player2Down);

    //fileWrite << gameDifficultyDef << '\n';
    //fileWrite << player1UpDef << '\n';
    //fileWrite << player1DownDef << '\n';
    //fileWrite << player2UpDef << '\n';
    //fileWrite << player2DownDef << '\n';

    //fileWrite.close();
//}

