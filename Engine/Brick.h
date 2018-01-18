#pragma once
#include "Vec2.h"
#include "Rekt.h"

class Brick
{

public:
    Brick(Vec2 pos_in, char type_in);
    
    char GetType() const;
    Vec2 GetPos() const;
    void SetType(char c);
    void Destroy();
    bool IsAlive();
    Rekt GetRekt() const;

private:
    Vec2 pos;
    char type;
    bool is_alive = true;
    static constexpr float width = 32.0f;
    static constexpr float height = 64.0f;

};