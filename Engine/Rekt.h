#pragma once

class Rekt
{
public:
    Rekt() = default;
    Rekt(float top_in, float bottom_in, float left_in, float right_in);
    bool IsOverlappingWith(const Rekt other);

private:
    float top;
    float bottom;
    float left;
    float right;
};