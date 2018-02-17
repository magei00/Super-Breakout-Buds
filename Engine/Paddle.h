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
    void Reset();
    bool IsCollidingWith(Ball& ball);
    void BounceBall(Ball& ball);
    void HandleSticky(Ball& ball);
    void Draw(Graphics& gfx);
private:
    Vec2 pos;
    Vec2 defaultPos;
    float speed = 500.0f;
    int stickyCharges = 1;
    static constexpr float minBounceAngle = -40.0f; //degrees
    static constexpr float maxBounceAngle = 40.0f; //degrees
    float totalBounceRange = std::abs(minBounceAngle) + std::abs(maxBounceAngle);
    static constexpr int nBounceAngles = 8; //has to be a even number, otherwise there will be a perpendicular angle.
    Vec2 bounceAngles[nBounceAngles];
    int ctrlScheme; // 1 is for player 1 (W & S) 2 is for player 2 (up and down)
    static constexpr float width = 24.0f;
    static constexpr float height = 160.0f;
};