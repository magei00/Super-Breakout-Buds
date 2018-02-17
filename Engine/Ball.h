#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Rekt.h"

class Ball
{
public:
    Ball() = default;
    void Init(Vec2 pos_in, Vec2 vel_in, char type_in);
    void Update(float dt);
    void Reset();
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
    void SetStuck(bool isStuck);
    bool IsStuck();
    void Kill();
    void Draw(Graphics& gfx);
private:
    
    Vec2 pos=Vec2(-100.0f,-100.0f);
    Vec2 defaultPos;
    Vec2 vel = Vec2(0.0f, 0.0f);
    Vec2 defaultVel;
    bool stuck=false;
    float speed=500;
    char type;
    static constexpr float width = 24.0f;
    static constexpr float height = 24.0f;
    bool isAlive = false;
};