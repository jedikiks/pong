#ifndef BALL_H
#define BALL_H
#include "raylib.h"

class Ball {
    private:
        float m_x {};
        float m_y {};
        float def_m_x {};
        float def_m_y {};
        float m_radius {};
        float m_speedX {};
        float m_speedY {};
        float def_m_speedX {};
        float def_m_speedY {};
        Color m_color {};
    public:
        Ball(float x, float y, float radius, float speedX, float speedY, Color color);

        float getX() {return m_x;}
        float getY() {return m_y;}
        float getRadius() {return m_radius;}
        float getSpeedX () {return m_speedX;}
        float getSpeedY () {return m_speedY;}

        void Draw();
        void moveX ();
        void moveY ();
        void setSpeedX (int speed);
        void setSpeedY (int speed);
        void checkYCollision();
        void flipDir(char dir);
        void reset();
        int getRandomDir();
        Vector2 getCenter();

};

#endif