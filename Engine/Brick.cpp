#include "Brick.h"

Brick::Brick(Vec2 pos_in, char type_in)
{
    pos = pos_in;
    type = type_in;
    is_alive = true;
}

char Brick::GetType() const
{
    return type;
}

Vec2 Brick::GetPos() const
{
    return pos;
}

void Brick::SetType(char c)
{
    type = c;
}

void Brick::Destroy()
{
    is_alive = false;
}
bool Brick::IsAlive()
{
    return is_alive;
}

Rekt Brick::GetRekt() const
{
    return Rekt(pos,width,height);
}
