#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"
#include "Rekt.h"

class Paddle
{
public:
    Paddle(Vec2 pos_in, int ctrlScheme_in);
    void Update(Keyboard& kbd);
    bool IsCollidingWith(Ball ball);
    void Draw(Graphics& gfx);
private:
    Vec2 pos;
    float speed = 5.0f;
    int ctrlScheme; // 1 is for player 1 (W & S) 2 is for player 2 (up and down)
    static constexpr float width = 24.0f;
    static constexpr float height = 160.0f;
};