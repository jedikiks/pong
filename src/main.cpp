#include "raylib.h"

typedef int Player;

class Ball {
    private:
        float m_x {};
        float m_y {};
        float def_m_x {};
        float def_m_y {};
        float m_radius {};
        float m_speedX {};
        float m_speedY {};
        Color m_color {};
    public:
        Ball(float x, float y, float radius, float speedX, float speedY, Color color) {
            m_x = x;
            m_y = y;
            def_m_x = x;
            def_m_y = y;
            m_radius = radius;
            m_speedX = speedX;
            m_speedY = speedY;
            m_color = color;
        }

        void Draw() {
            DrawCircle(m_x, m_y, m_radius, m_color);
        }

        void setSpeedX (int xSpeed) {
            m_x += m_speedX * GetFrameTime();
        }

        void setSpeedY (int ySpeed) {
            m_y += m_speedY * GetFrameTime();
        }

        float getSpeedX () {
            return m_speedX;
        }

        float getSpeedY () {
            return m_speedY;
        }

        void isBallInBounds() {
            if (m_y > GetScreenHeight()) {
                    m_y = GetScreenHeight();
                    flipDir('y');
            } else if (m_y < 0) {
                m_y = 0;
                flipDir('y');
            }
        }

        float getRadius() {
            return m_radius;
        }

        void flipDir(char dir) {
            if (dir == 'x') {m_speedX *= -1;}
            if (dir == 'y') {m_speedY *= -1;}
        }

        Vector2 getCenter() {
            Vector2 vector {m_x, m_y};
            return vector; 
        }

        float getX() {
            return m_x;
        }

        float getY() {
            return m_y;
        }

        void reset() {
            m_x = def_m_x;
            m_y = def_m_y;
        }


};

class Paddle {
    private:
        float m_x {};
        float m_y {};
        float m_width {};
        float m_height {};
        float m_speed {};
        Color m_color {};

    public:
        Paddle(float x, float y, int width, int height, int speed, Color color) {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
        m_speed = speed;
        m_color = color;
        }

        void keyPress(Player player) {
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
        
        Vector2 getCenter() {
            Vector2 vector {m_x, m_y};
            return vector; 
        }

        Rectangle getRectangle() {
            return Rectangle {m_x - m_width / 2, m_y - m_height / 2, m_width, m_height};
        }

        void Draw() {
            DrawRectangleRec(getRectangle(), m_color);
        }

        void checkCollision(Ball& ball, Player player) {
        if (CheckCollisionCircleRec(ball.getCenter(), ball.getRadius(), getRectangle())) {
            if (player == 1) {
                if (ball.getSpeedX() < 0) {
                    ball.flipDir('x');
                }
            } else if (player == 2) {
                if (ball.getSpeedX() > 0) {
                    ball.flipDir('x');
                }
            }

        }
        }

//TODO: ball ghosts past right ball when screen is resized        
        void updateWidth() {
            m_x = GetScreenWidth() - 20.0f;
        }

};

int main() {
    InitWindow(800, 640, "Pong");
    SetWindowPosition(GetScreenWidth() / 2, GetScreenHeight() / 2);

    Ball ball {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 5.0f, 300.0f, 300.0f, WHITE};
    Paddle leftPaddle {20, GetScreenHeight() / 2.0f, 10, 100, 500, WHITE};
    Paddle rightPaddle {GetScreenWidth() - 20.0f, GetScreenHeight() / 2.0f, 10, 100, 500, WHITE};

    while (!WindowShouldClose()) {
        ball.setSpeedX(100);
        ball.setSpeedY(300);

        ball.isBallInBounds();

        leftPaddle.keyPress(1);
        rightPaddle.keyPress(2);

        rightPaddle.checkCollision(ball, 2);
        leftPaddle.checkCollision(ball, 1);

        if (ball.getX() > GetScreenWidth() || ball.getX() < 0) {
            ball.reset();
        }


        BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(10, 10);
            SetWindowState(FLAG_VSYNC_HINT);

            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}