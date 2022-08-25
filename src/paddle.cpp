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

void Paddle::movePaddleY (const KeyboardKey& key0, const KeyboardKey key1) {
    if (IsKeyDown(key0)) {
        m_y -= m_speed * GetFrameTime();
    } else if (IsKeyDown(key1)) {
        m_y += m_speed * GetFrameTime();
    }
}

void Paddle::keyPress(Player player) {
        if (player == 1) {
            Paddle::movePaddleY(KEY_W, KEY_S);
        } else if (player == 2) {
            //TODO: put movepaddley function here
            Paddle::movePaddleY(KEY_UP, KEY_DOWN);
        }
}

void Paddle::Draw() {
            DrawRectangleRec(Paddle::getRectangle(), m_color);
}

void Paddle::reset() {
    m_x = def_m_x;
    m_y = def_m_y;
}

void Paddle::setX(float x) {
    m_x = x;
}

void Paddle::setY(float y) {
    m_y = y;
}

void Paddle::checkBounds() {
    if (m_y > GetScreenHeight() ) {
        m_y = GetScreenHeight();
    } else if (m_y < 0) {
        m_y = 0;
    }
}
