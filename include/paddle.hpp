#ifndef PADDLE_H
#define PADDLE_H
#include "raylib.h"
#include "../include/types.hpp"

class Paddle {
    private:
        float m_x {};
        float m_y {};
        float m_width {};
        float m_height {};
        float m_speed {};
        Color m_color {};

    public:
        Paddle(float x, float y, int width, int height, int speed, Color color);
        
        Vector2 getCenter() { return Vector2 {m_x, m_y}; }
        Rectangle getRectangle() { return Rectangle {m_x - m_width / 2, m_y - m_height / 2, m_width, m_height}; }

        void Draw();
        void keyPress(Player player); 

};

#endif