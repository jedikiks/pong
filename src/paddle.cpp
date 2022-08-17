#include "raylib.h"
#include "../include/paddle.hpp"
#include "../include/types.hpp"

Paddle::Paddle(float x, float y, int width, int height, float speed, Color color) {
    m_x = x;
    m_y = y;
    def_m_x = x;
    def_m_y = y;
    m_width = width;
    m_height = height;
    m_speed = speed;
    m_color = color;
}

void Paddle::keyPress(Player player) {
        if (player == 1) {
            if (IsKeyDown(KEY_W)) {
                m_y -= m_speed * GetFrameTime();
            } else if (IsKeyDown(KEY_S)) {
                m_y += m_speed * GetFrameTime();
            }
        } else if (player == 2) {
            if (IsKeyDown(KEY_UP)) {
                m_y -= m_speed * GetFrameTime();
            } else if (IsKeyDown(KEY_DOWN)) {
                m_y += m_speed * GetFrameTime();
            }
        }
}

void Paddle::Draw() {
            DrawRectangleRec(Paddle::getRectangle(), m_color);
}

void Paddle::reset() {
    m_x = def_m_x;
    m_y = def_m_y;
}