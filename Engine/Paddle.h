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
    void Update(Keyboard& kbd, float dt);
    bool IsCollidingWith(Ball& ball);
    void BounceBall(Ball& ball);
    void Draw(Graphics& gfx);
private:
    Vec2 pos;
    float speed = 300.0f;
    static constexpr float minBounceAngle = -45.0f; //degrees
    static constexpr float maxBounceAngle = 45.0f; //degrees
    float totalBounceRange = std::abs(minBounceAngle) + std::abs(maxBounceAngle);
    static constexpr int nBounceAngles = 4;
    Vec2 bounceAngles[nBounceAngles];
    int ctrlScheme; // 1 is for player 1 (W & S) 2 is for player 2 (up and down)
    static constexpr float width = 24.0f;
    static constexpr float height = 160.0f;
};