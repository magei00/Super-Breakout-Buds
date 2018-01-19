#pragma once
#include <cmath>

class Vec2
{

public:
    Vec2() = default;
    Vec2(float x_in,float y_in);
    Vec2 operator+(Vec2 rhs);
    
    Vec2& operator+=(Vec2 rhs);
    Vec2 operator-(Vec2 rhs);
    Vec2& operator-=(Vec2 rhs);
    Vec2 operator*(float rhs);
    float GetLengthSquared();
    float GetLength();
    Vec2 Normalize();
    Vec2 RotateRad(float radians);
    Vec2 RotateDeg(float degrees);

    float x;
    float y;
    
};