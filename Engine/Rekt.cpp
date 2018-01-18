#include "Rekt.h"

Rekt::Rekt(float top_in, float bottom_in, float left_in, float right_in)
{
    top = top_in;
    bottom = bottom_in;
    left = left_in;
    right = right_in;
}

bool Rekt::IsOverlappingWith(const Rekt other)
{
    if (top <= other.bottom &&
        bottom >= other.top &&
        left <= other.right &&
        right >= other.left)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
