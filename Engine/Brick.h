#pragma once
#include "Vec2.h"
#include "Rekt.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{

public:
    Brick() = default;
    Brick(Vec2 pos_in, char type_in);
    void Init(Vec2 pos_in, char type_in);
    
    char GetType() const;
    Vec2 GetPos() const;
    void SetType(char c);
    void Destroy();
    void Revive();
    bool IsAlive();
    Rekt GetRekt() const;
    static float GetWidth();
    static float GetHeight();
    bool IsCollidingWithBall(Ball ball);
    void Draw(Graphics& gfx);

private:
    Vec2 pos;
    char type;
    bool is_alive = true;
    static constexpr float width = 32.0f;
    static constexpr float height = 64.0f;

};