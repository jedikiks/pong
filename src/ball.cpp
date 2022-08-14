#include "raylib.h"
#include "../include/ball.hpp"


Ball::Ball(float x, float y, float radius, float speedX, float speedY, Color color) {
    m_x = x;
    m_y = y;
    def_m_x = x;
    def_m_y = y;
    m_radius = radius;
    m_speedX = speedX;
    m_speedY = speedY;
    m_color = color;
}


void Ball::Draw() {
    Vector2 getCenter();
    DrawCircle(m_x, m_y, m_radius, m_color);
}

void Ball::setSpeedX (int xSpeed) {
    m_x += m_speedX * GetFrameTime();
}

void Ball::setSpeedY (int ySpeed) {
    m_y += m_speedY * GetFrameTime();
}

void Ball::isBallInBounds() {
    if (m_y > GetScreenHeight()) {
            m_y = GetScreenHeight();
            Ball::flipDir('y');
    } else if (m_y < 0) {
        m_y = 0;
        Ball::flipDir('y');
    }
}


void Ball::flipDir(char dir) {
    if (dir == 'x') {m_speedX *= -1;}
    if (dir == 'y') {m_speedY *= -1.1;}
}

Vector2 Ball::getCenter() {
    Vector2 vector {m_x, m_y};
    return vector; 
}

void Ball::reset() {
    m_x = def_m_x;
    m_y = def_m_y;
}
