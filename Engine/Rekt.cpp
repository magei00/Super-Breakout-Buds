#include "Rekt.h"

Rekt::Rekt(float top_in, float bottom_in, float left_in, float right_in)
    :
    top(top_in),
    bottom(bottom_in),
    left (left_in),
    right(right_in)
{
   
}

Rekt::Rekt(Vec2 pos, float width, float height)
    :Rekt(pos.y, pos.y + height, pos.x, pos.x + width)
{
}

bool Rekt::IsOverlappingWith(const Rekt other) const
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
