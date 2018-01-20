#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Rekt.h"

class Ball
{
public:
    Ball(Vec2 pos_in, Vec2 vel_in, char type_in);
    void Update(float dt);
    void BounceX();
    void BounceY();
    void BounceUp();
    void BounceDown();
    void BounceLeft();
    void BounceRight();
    Vec2 GetPos();
    Rekt GetRekt();
    float GetWidth();
    float GetHeight();
    void SetVel(Vec2 vel_in);
    bool IsAlive();
    void Draw(Graphics& gfx);
private:
    Vec2 pos;
    Vec2 vel;
    float speed=500;
    char type;
    static constexpr float width = 24.0f;
    static constexpr float height = 24.0f;
    bool isAlive = true;
};