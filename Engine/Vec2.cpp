#include "Vec2.h"

Vec2::Vec2(float x_in, float y_in)
{
    x = x_in;
    y = y_in;
}

Vec2 Vec2::operator+(Vec2 rhs)
{
    return Vec2(x+rhs.x,y+rhs.y);
}



Vec2& Vec2::operator+=(Vec2 rhs)
{
    return (*this = *this+rhs);
}

Vec2 Vec2::operator-(Vec2 rhs)
{
    return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 & Vec2::operator-=(Vec2 rhs)
{
    return (*this = *this - rhs);
}

Vec2 Vec2::operator*(float rhs)
{
    return Vec2(x*rhs,y*rhs);
}

float Vec2::GetLengthSquared()
{
    return (x*x+y*y);
}

float Vec2::GetLength()
{
    return std::sqrt(GetLengthSquared());
}

Vec2 Vec2::Normalize()
{
    if (GetLength() != 0) {
        return *this * (1.0f / GetLength());
    }
    else
    {
        return Vec2(0.0f, 0.0f);
    }
}

Vec2 Vec2::RotateRad(float radians)
{
    float oldX = x;
    float oldY = y;
    float newX = oldX*std::cos(radians) - oldY*std::sin(radians);
    float newY = oldX*std::sin(radians) + oldY*std::cos(radians);

    return Vec2(newX,newY);
}

Vec2 Vec2::RotateDeg(float degrees)
{
    const float PI = 3.1415927;
    return RotateRad(PI*degrees/180);
}
