#pragma once
#include "Vec2.h"

class Rekt
{
public:
    Rekt() = default;
    Rekt(float top_in, float bottom_in, float left_in, float right_in);
    Rekt(Vec2 pos, float width, float height);
    bool IsOverlappingWith(const Rekt other) const;

private:
    float top;
    float bottom;
    float left;
    float right;
};