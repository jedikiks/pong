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
    def_m_speedX = m_speedX; 
    def_m_speedY = m_speedY; 
    m_color = color;
}


void Ball::Draw() {
    DrawCircle(m_x, m_y, m_radius, m_color);
}

void Ball::setSpeedX (int speed) {
    m_speedX = speed;
}

void Ball::setSpeedY (int speed) {
    m_speedY = speed;
}

void Ball::moveX () {
    m_x += m_speedX * GetFrameTime();
}

void Ball::moveY () {
    m_y += m_speedY * GetFrameTime();
}

void Ball::checkYCollision() {
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
    if (dir == 'y') {m_speedY *= -1;}
}

Vector2 Ball::getCenter() {
    Vector2 vector {m_x, m_y};
    return vector; 
}

int Ball::getRandomDir() {
    if (GetRandomValue(0, 1) == 0) {
        return -1;
    } else {
        return 1;
    }
}

void Ball::reset() {
    m_x = def_m_x;
    m_y = def_m_y;
    m_speedX = def_m_speedX * getRandomDir() + GetRandomValue(1, 200); 
    m_speedY = def_m_speedY * getRandomDir() + GetRandomValue(1, 200); 
}
