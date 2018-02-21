#include "Ball.h"

/*Ball::Ball(Vec2 pos_in, Vec2 vel_in, char type_in)
{
    pos = pos_in;
    vel = vel_in;
    type = type_in;
}*/

void Ball::Init(Vec2 pos_in, Vec2 vel_in, char type_in)
{
    pos = defaultPos = pos_in;
    vel = defaultVel = vel_in;
    type =defaultType = type_in;
    isAlive = true;
}

void Ball::Update(float dt)
{
    //move
    //vel = vel.Normalize();

    if (!stuck && isAlive) {
        pos += vel*speed*dt;
    }
    

    //collision with top and bottom of level
    if (pos.y < 0)
    {
        pos.y = 0 + pos.y*-1;
        BounceY();
    }
    if (pos.y >= 600-height)
    {
        pos.y = 600-height - ((pos.y+height)-600);
        BounceY();
    }
    if (pos.x >= 800-width || pos.x < 0)//check if past paddles and outside level
    {
        isAlive = false;
        pos.x = 0;
        BounceX();
    }

}

void Ball::Reset()
{
    isAlive = true;
    pos = defaultPos;
    vel = defaultVel;
    type = defaultType;
}

void Ball::BounceX()
{
    vel.x *= -1;
}

void Ball::BounceY()
{
    vel.y *= -1;
}

void Ball::BounceUp()
{
    vel.y = std::abs(vel.y)*-1;
}

void Ball::BounceDown()
{
    vel.y = std::abs(vel.y);
}

void Ball::BounceLeft()
{
    vel.x = std::abs(vel.x)*-1;
}

void Ball::BounceRight()
{
    vel.x = std::abs(vel.x);
}

Vec2 Ball::GetPos()
{
    return pos;
}

Rekt Ball::GetRekt()
{
    return Rekt(pos,width,height);
}

float Ball::GetWidth()
{
    return width;
}

float Ball::GetHeight()
{
    return height;
}

char Ball::GetType()
{
    return type;
}

void Ball::SetVel(Vec2 vel_in)
{
    vel = vel_in;
}

bool Ball::IsAlive()
{
    return isAlive;
}

void Ball::ChangeType(char t)
{
    type = t;
}

void Ball::SetStuck(bool isStuck)
{
    stuck = isStuck;
}

bool Ball::IsStuck()
{
    return stuck;
}

void Ball::Kill()
{
    isAlive = false;
    pos = Vec2(-100.0f, -100.0f);
    vel = Vec2(0.0f, 0.0f);
}

void Ball::Draw(Graphics & gfx)
{
    const int x = int(pos.x);
    const int y = int(pos.y);

    if (type == 'r') 
    {
            gfx.PutPixel(7 + x, 0 + y, 106, 14, 14);
            gfx.PutPixel(8 + x, 0 + y, 98, 12, 10);
            gfx.PutPixel(9 + x, 0 + y, 86, 12, 8);
            gfx.PutPixel(10 + x, 0 + y, 69, 11, 6);
            gfx.PutPixel(11 + x, 0 + y, 47, 11, 5);
            gfx.PutPixel(12 + x, 0 + y, 41, 10, 4);
            gfx.PutPixel(13 + x, 0 + y, 62, 8, 5);
            gfx.PutPixel(14 + x, 0 + y, 75, 7, 3);
            gfx.PutPixel(15 + x, 0 + y, 86, 5, 3);
            gfx.PutPixel(16 + x, 0 + y, 93, 3, 3);
            gfx.PutPixel(6 + x, 1 + y, 93, 14, 12);
            gfx.PutPixel(7 + x, 1 + y, 43, 11, 6);
            gfx.PutPixel(8 + x, 1 + y, 50, 14, 6);
            gfx.PutPixel(9 + x, 1 + y, 59, 17, 7);
            gfx.PutPixel(10 + x, 1 + y, 65, 18, 7);
            gfx.PutPixel(11 + x, 1 + y, 69, 19, 7);
            gfx.PutPixel(12 + x, 1 + y, 69, 19, 8);
            gfx.PutPixel(13 + x, 1 + y, 66, 18, 6);
            gfx.PutPixel(14 + x, 1 + y, 59, 16, 6);
            gfx.PutPixel(15 + x, 1 + y, 49, 13, 4);
            gfx.PutPixel(16 + x, 1 + y, 37, 10, 3);
            gfx.PutPixel(17 + x, 1 + y, 67, 4, 2);
            gfx.PutPixel(18 + x, 1 + y, 97, 0, 0);
            gfx.PutPixel(4 + x, 2 + y, 111, 17, 17);
            gfx.PutPixel(5 + x, 2 + y, 68, 13, 9);
            gfx.PutPixel(6 + x, 2 + y, 50, 15, 7);
            gfx.PutPixel(7 + x, 2 + y, 67, 20, 9);
            gfx.PutPixel(8 + x, 2 + y, 80, 23, 10);
            gfx.PutPixel(9 + x, 2 + y, 90, 25, 11);
            gfx.PutPixel(10 + x, 2 + y, 96, 26, 12);
            gfx.PutPixel(11 + x, 2 + y, 98, 27, 11);
            gfx.PutPixel(12 + x, 2 + y, 97, 26, 10);
            gfx.PutPixel(13 + x, 2 + y, 94, 25, 10);
            gfx.PutPixel(14 + x, 2 + y, 87, 23, 8);
            gfx.PutPixel(15 + x, 2 + y, 78, 20, 8);
            gfx.PutPixel(16 + x, 2 + y, 66, 17, 5);
            gfx.PutPixel(17 + x, 2 + y, 50, 14, 4);
            gfx.PutPixel(18 + x, 2 + y, 45, 8, 3);
            gfx.PutPixel(19 + x, 2 + y, 84, 1, 1);
            gfx.PutPixel(3 + x, 3 + y, 99, 14, 14);
            gfx.PutPixel(4 + x, 3 + y, 42, 11, 6);
            gfx.PutPixel(5 + x, 3 + y, 57, 18, 8);
            gfx.PutPixel(6 + x, 3 + y, 78, 23, 11);
            gfx.PutPixel(7 + x, 3 + y, 95, 28, 13);
            gfx.PutPixel(8 + x, 3 + y, 108, 30, 14);
            gfx.PutPixel(9 + x, 3 + y, 117, 32, 15);
            gfx.PutPixel(10 + x, 3 + y, 123, 33, 15);
            gfx.PutPixel(11 + x, 3 + y, 125, 33, 15);
            gfx.PutPixel(12 + x, 3 + y, 124, 32, 14);
            gfx.PutPixel(13 + x, 3 + y, 120, 31, 12);
            gfx.PutPixel(14 + x, 3 + y, 113, 29, 11);
            gfx.PutPixel(15 + x, 3 + y, 103, 27, 10);
            gfx.PutPixel(16 + x, 3 + y, 91, 24, 8);
            gfx.PutPixel(17 + x, 3 + y, 75, 20, 6);
            gfx.PutPixel(18 + x, 3 + y, 58, 15, 5);
            gfx.PutPixel(19 + x, 3 + y, 37, 10, 3);
            gfx.PutPixel(20 + x, 3 + y, 66, 2, 1);
            gfx.PutPixel(2 + x, 4 + y, 100, 13, 13);
            gfx.PutPixel(3 + x, 4 + y, 43, 11, 6);
            gfx.PutPixel(4 + x, 4 + y, 58, 18, 8);
            gfx.PutPixel(5 + x, 4 + y, 83, 25, 12);
            gfx.PutPixel(6 + x, 4 + y, 103, 30, 15);
            gfx.PutPixel(7 + x, 4 + y, 120, 34, 17);
            gfx.PutPixel(8 + x, 4 + y, 133, 37, 18);
            gfx.PutPixel(9 + x, 4 + y, 142, 38, 19);
            gfx.PutPixel(10 + x, 4 + y, 147, 39, 19);
            gfx.PutPixel(11 + x, 4 + y, 149, 38, 18);
            gfx.PutPixel(12 + x, 4 + y, 148, 37, 17);
            gfx.PutPixel(13 + x, 4 + y, 143, 36, 16);
            gfx.PutPixel(14 + x, 4 + y, 136, 34, 14);
            gfx.PutPixel(15 + x, 4 + y, 126, 31, 12);
            gfx.PutPixel(16 + x, 4 + y, 114, 29, 11);
            gfx.PutPixel(17 + x, 4 + y, 97, 25, 9);
            gfx.PutPixel(18 + x, 4 + y, 79, 20, 7);
            gfx.PutPixel(19 + x, 4 + y, 57, 15, 5);
            gfx.PutPixel(20 + x, 4 + y, 34, 9, 3);
            gfx.PutPixel(21 + x, 4 + y, 83, 1, 1);
            gfx.PutPixel(2 + x, 5 + y, 69, 11, 9);
            gfx.PutPixel(3 + x, 5 + y, 52, 16, 8);
            gfx.PutPixel(4 + x, 5 + y, 80, 24, 12);
            gfx.PutPixel(5 + x, 5 + y, 105, 31, 16);
            gfx.PutPixel(6 + x, 5 + y, 127, 37, 19);
            gfx.PutPixel(7 + x, 5 + y, 143, 41, 21);
            gfx.PutPixel(8 + x, 5 + y, 155, 42, 22);
            gfx.PutPixel(9 + x, 5 + y, 164, 43, 22);
            gfx.PutPixel(10 + x, 5 + y, 169, 43, 22);
            gfx.PutPixel(11 + x, 5 + y, 172, 43, 21);
            gfx.PutPixel(12 + x, 5 + y, 170, 41, 20);
            gfx.PutPixel(13 + x, 5 + y, 165, 39, 19);
            gfx.PutPixel(14 + x, 5 + y, 157, 38, 17);
            gfx.PutPixel(15 + x, 5 + y, 146, 35, 15);
            gfx.PutPixel(16 + x, 5 + y, 134, 32, 13);
            gfx.PutPixel(17 + x, 5 + y, 117, 29, 11);
            gfx.PutPixel(18 + x, 5 + y, 98, 25, 9);
            gfx.PutPixel(19 + x, 5 + y, 77, 20, 7);
            gfx.PutPixel(20 + x, 5 + y, 54, 14, 4);
            gfx.PutPixel(21 + x, 5 + y, 39, 7, 2);
            gfx.PutPixel(22 + x, 5 + y, 97, 0, 0);
            gfx.PutPixel(1 + x, 6 + y, 88, 10, 10);
            gfx.PutPixel(2 + x, 6 + y, 38, 12, 5);
            gfx.PutPixel(3 + x, 6 + y, 70, 21, 10);
            gfx.PutPixel(4 + x, 6 + y, 98, 29, 14);
            gfx.PutPixel(5 + x, 6 + y, 124, 35, 19);
            gfx.PutPixel(6 + x, 6 + y, 146, 42, 22);
            gfx.PutPixel(7 + x, 6 + y, 163, 45, 24);
            gfx.PutPixel(8 + x, 6 + y, 176, 47, 25);
            gfx.PutPixel(9 + x, 6 + y, 184, 47, 26);
            gfx.PutPixel(10 + x, 6 + y, 189, 47, 26);
            gfx.PutPixel(11 + x, 6 + y, 191, 45, 25);
            gfx.PutPixel(12 + x, 6 + y, 188, 43, 23);
            gfx.PutPixel(13 + x, 6 + y, 183, 42, 21);
            gfx.PutPixel(14 + x, 6 + y, 175, 40, 19);
            gfx.PutPixel(15 + x, 6 + y, 165, 38, 17);
            gfx.PutPixel(16 + x, 6 + y, 151, 36, 15);
            gfx.PutPixel(17 + x, 6 + y, 134, 32, 12);
            gfx.PutPixel(18 + x, 6 + y, 116, 28, 10);
            gfx.PutPixel(19 + x, 6 + y, 94, 23, 8);
            gfx.PutPixel(20 + x, 6 + y, 70, 18, 6);
            gfx.PutPixel(21 + x, 6 + y, 43, 12, 4);
            gfx.PutPixel(22 + x, 6 + y, 57, 3, 1);
            gfx.PutPixel(1 + x, 7 + y, 35, 7, 4);
            gfx.PutPixel(2 + x, 7 + y, 53, 16, 7);
            gfx.PutPixel(3 + x, 7 + y, 84, 25, 11);
            gfx.PutPixel(4 + x, 7 + y, 113, 32, 16);
            gfx.PutPixel(5 + x, 7 + y, 138, 39, 20);
            gfx.PutPixel(6 + x, 7 + y, 160, 44, 23);
            gfx.PutPixel(7 + x, 7 + y, 179, 47, 27);
            gfx.PutPixel(8 + x, 7 + y, 192, 49, 29);
            gfx.PutPixel(9 + x, 7 + y, 200, 49, 29);
            gfx.PutPixel(10 + x, 7 + y, 205, 48, 28);
            gfx.PutPixel(11 + x, 7 + y, 206, 46, 27);
            gfx.PutPixel(12 + x, 7 + y, 204, 45, 26);
            gfx.PutPixel(13 + x, 7 + y, 199, 43, 24);
            gfx.PutPixel(14 + x, 7 + y, 190, 42, 22);
            gfx.PutPixel(15 + x, 7 + y, 179, 40, 19);
            gfx.PutPixel(16 + x, 7 + y, 165, 38, 16);
            gfx.PutPixel(17 + x, 7 + y, 149, 35, 14);
            gfx.PutPixel(18 + x, 7 + y, 129, 31, 12);
            gfx.PutPixel(19 + x, 7 + y, 108, 27, 10);
            gfx.PutPixel(20 + x, 7 + y, 84, 22, 7);
            gfx.PutPixel(21 + x, 7 + y, 56, 15, 5);
            gfx.PutPixel(22 + x, 7 + y, 27, 8, 2);
            gfx.PutPixel(23 + x, 7 + y, 86, 0, 0);
            gfx.PutPixel(0 + x, 8 + y, 88, 10, 10);
            gfx.PutPixel(1 + x, 8 + y, 30, 9, 3);
            gfx.PutPixel(2 + x, 8 + y, 65, 18, 8);
            gfx.PutPixel(3 + x, 8 + y, 95, 27, 12);
            gfx.PutPixel(4 + x, 8 + y, 123, 34, 16);
            gfx.PutPixel(5 + x, 8 + y, 148, 40, 21);
            gfx.PutPixel(6 + x, 8 + y, 170, 45, 25);
            gfx.PutPixel(7 + x, 8 + y, 190, 48, 28);
            gfx.PutPixel(8 + x, 8 + y, 204, 50, 30);
            gfx.PutPixel(9 + x, 8 + y, 214, 50, 31);
            gfx.PutPixel(10 + x, 8 + y, 218, 48, 31);
            gfx.PutPixel(11 + x, 8 + y, 219, 46, 30);
            gfx.PutPixel(12 + x, 8 + y, 217, 44, 28);
            gfx.PutPixel(13 + x, 8 + y, 211, 43, 26);
            gfx.PutPixel(14 + x, 8 + y, 203, 42, 23);
            gfx.PutPixel(15 + x, 8 + y, 191, 41, 21);
            gfx.PutPixel(16 + x, 8 + y, 177, 39, 19);
            gfx.PutPixel(17 + x, 8 + y, 161, 37, 16);
            gfx.PutPixel(18 + x, 8 + y, 141, 34, 13);
            gfx.PutPixel(19 + x, 8 + y, 120, 29, 11);
            gfx.PutPixel(20 + x, 8 + y, 95, 24, 8);
            gfx.PutPixel(21 + x, 8 + y, 68, 18, 6);
            gfx.PutPixel(22 + x, 8 + y, 39, 10, 3);
            gfx.PutPixel(23 + x, 8 + y, 72, 1, 0);
            gfx.PutPixel(0 + x, 9 + y, 83, 7, 7);
            gfx.PutPixel(1 + x, 9 + y, 38, 11, 5);
            gfx.PutPixel(2 + x, 9 + y, 72, 21, 9);
            gfx.PutPixel(3 + x, 9 + y, 103, 28, 13);
            gfx.PutPixel(4 + x, 9 + y, 131, 36, 17);
            gfx.PutPixel(5 + x, 9 + y, 155, 41, 21);
            gfx.PutPixel(6 + x, 9 + y, 178, 45, 24);
            gfx.PutPixel(7 + x, 9 + y, 196, 48, 28);
            gfx.PutPixel(8 + x, 9 + y, 212, 49, 30);
            gfx.PutPixel(9 + x, 9 + y, 222, 49, 31);
            gfx.PutPixel(10 + x, 9 + y, 227, 47, 32);
            gfx.PutPixel(11 + x, 9 + y, 229, 44, 31);
            gfx.PutPixel(12 + x, 9 + y, 227, 43, 29);
            gfx.PutPixel(13 + x, 9 + y, 221, 42, 28);
            gfx.PutPixel(14 + x, 9 + y, 213, 41, 25);
            gfx.PutPixel(15 + x, 9 + y, 201, 41, 23);
            gfx.PutPixel(16 + x, 9 + y, 187, 40, 20);
            gfx.PutPixel(17 + x, 9 + y, 170, 38, 18);
            gfx.PutPixel(18 + x, 9 + y, 151, 35, 14);
            gfx.PutPixel(19 + x, 9 + y, 128, 32, 12);
            gfx.PutPixel(20 + x, 9 + y, 104, 26, 9);
            gfx.PutPixel(21 + x, 9 + y, 76, 20, 6);
            gfx.PutPixel(22 + x, 9 + y, 47, 12, 4);
            gfx.PutPixel(23 + x, 9 + y, 60, 3, 1);
            gfx.PutPixel(0 + x, 10 + y, 70, 6, 5);
            gfx.PutPixel(1 + x, 10 + y, 44, 13, 5);
            gfx.PutPixel(2 + x, 10 + y, 77, 22, 9);
            gfx.PutPixel(3 + x, 10 + y, 107, 29, 13);
            gfx.PutPixel(4 + x, 10 + y, 134, 36, 17);
            gfx.PutPixel(5 + x, 10 + y, 159, 41, 20);
            gfx.PutPixel(6 + x, 10 + y, 181, 45, 24);
            gfx.PutPixel(7 + x, 10 + y, 200, 47, 27);
            gfx.PutPixel(8 + x, 10 + y, 215, 48, 29);
            gfx.PutPixel(9 + x, 10 + y, 226, 48, 32);
            gfx.PutPixel(10 + x, 10 + y, 232, 44, 32);
            gfx.PutPixel(11 + x, 10 + y, 234, 41, 32);
            gfx.PutPixel(12 + x, 10 + y, 232, 39, 30);
            gfx.PutPixel(13 + x, 10 + y, 227, 39, 28);
            gfx.PutPixel(14 + x, 10 + y, 218, 41, 26);
            gfx.PutPixel(15 + x, 10 + y, 207, 42, 24);
            gfx.PutPixel(16 + x, 10 + y, 193, 41, 21);
            gfx.PutPixel(17 + x, 10 + y, 176, 39, 19);
            gfx.PutPixel(18 + x, 10 + y, 157, 37, 15);
            gfx.PutPixel(19 + x, 10 + y, 134, 33, 13);
            gfx.PutPixel(20 + x, 10 + y, 110, 27, 10);
            gfx.PutPixel(21 + x, 10 + y, 82, 22, 7);
            gfx.PutPixel(22 + x, 10 + y, 52, 14, 4);
            gfx.PutPixel(23 + x, 10 + y, 43, 5, 2);
            gfx.PutPixel(0 + x, 11 + y, 50, 5, 4);
            gfx.PutPixel(1 + x, 11 + y, 46, 13, 5);
            gfx.PutPixel(2 + x, 11 + y, 79, 22, 8);
            gfx.PutPixel(3 + x, 11 + y, 108, 29, 12);
            gfx.PutPixel(4 + x, 11 + y, 136, 36, 16);
            gfx.PutPixel(5 + x, 11 + y, 161, 40, 20);
            gfx.PutPixel(6 + x, 11 + y, 182, 44, 23);
            gfx.PutPixel(7 + x, 11 + y, 200, 45, 25);
            gfx.PutPixel(8 + x, 11 + y, 215, 46, 29);
            gfx.PutPixel(9 + x, 11 + y, 226, 45, 31);
            gfx.PutPixel(10 + x, 11 + y, 234, 42, 31);
            gfx.PutPixel(11 + x, 11 + y, 236, 36, 31);
            gfx.PutPixel(12 + x, 11 + y, 235, 34, 30);
            gfx.PutPixel(13 + x, 11 + y, 230, 37, 28);
            gfx.PutPixel(14 + x, 11 + y, 222, 40, 27);
            gfx.PutPixel(15 + x, 11 + y, 210, 41, 24);
            gfx.PutPixel(16 + x, 11 + y, 197, 41, 22);
            gfx.PutPixel(17 + x, 11 + y, 180, 40, 19);
            gfx.PutPixel(18 + x, 11 + y, 160, 37, 16);
            gfx.PutPixel(19 + x, 11 + y, 138, 33, 14);
            gfx.PutPixel(20 + x, 11 + y, 113, 28, 11);
            gfx.PutPixel(21 + x, 11 + y, 86, 22, 8);
            gfx.PutPixel(22 + x, 11 + y, 55, 15, 5);
            gfx.PutPixel(23 + x, 11 + y, 23, 6, 2);
            gfx.PutPixel(0 + x, 12 + y, 53, 4, 4);
            gfx.PutPixel(1 + x, 12 + y, 46, 13, 5);
            gfx.PutPixel(2 + x, 12 + y, 78, 22, 8);
            gfx.PutPixel(3 + x, 12 + y, 107, 28, 12);
            gfx.PutPixel(4 + x, 12 + y, 133, 35, 15);
            gfx.PutPixel(5 + x, 12 + y, 158, 39, 19);
            gfx.PutPixel(6 + x, 12 + y, 179, 43, 21);
            gfx.PutPixel(7 + x, 12 + y, 197, 44, 24);
            gfx.PutPixel(8 + x, 12 + y, 212, 44, 26);
            gfx.PutPixel(9 + x, 12 + y, 223, 43, 28);
            gfx.PutPixel(10 + x, 12 + y, 230, 40, 30);
            gfx.PutPixel(11 + x, 12 + y, 233, 36, 30);
            gfx.PutPixel(12 + x, 12 + y, 233, 34, 29);
            gfx.PutPixel(13 + x, 12 + y, 229, 37, 28);
            gfx.PutPixel(14 + x, 12 + y, 222, 40, 27);
            gfx.PutPixel(15 + x, 12 + y, 211, 42, 25);
            gfx.PutPixel(16 + x, 12 + y, 197, 42, 22);
            gfx.PutPixel(17 + x, 12 + y, 181, 41, 20);
            gfx.PutPixel(18 + x, 12 + y, 161, 38, 16);
            gfx.PutPixel(19 + x, 12 + y, 138, 34, 14);
            gfx.PutPixel(20 + x, 12 + y, 113, 29, 11);
            gfx.PutPixel(21 + x, 12 + y, 86, 23, 8);
            gfx.PutPixel(22 + x, 12 + y, 54, 15, 5);
            gfx.PutPixel(23 + x, 12 + y, 25, 6, 2);
            gfx.PutPixel(0 + x, 13 + y, 67, 4, 4);
            gfx.PutPixel(1 + x, 13 + y, 43, 12, 4);
            gfx.PutPixel(2 + x, 13 + y, 74, 21, 7);
            gfx.PutPixel(3 + x, 13 + y, 103, 27, 11);
            gfx.PutPixel(4 + x, 13 + y, 130, 33, 14);
            gfx.PutPixel(5 + x, 13 + y, 153, 37, 17);
            gfx.PutPixel(6 + x, 13 + y, 173, 41, 20);
            gfx.PutPixel(7 + x, 13 + y, 192, 42, 22);
            gfx.PutPixel(8 + x, 13 + y, 206, 43, 25);
            gfx.PutPixel(9 + x, 13 + y, 217, 42, 26);
            gfx.PutPixel(10 + x, 13 + y, 225, 40, 28);
            gfx.PutPixel(11 + x, 13 + y, 228, 38, 28);
            gfx.PutPixel(12 + x, 13 + y, 228, 38, 28);
            gfx.PutPixel(13 + x, 13 + y, 225, 39, 27);
            gfx.PutPixel(14 + x, 13 + y, 218, 41, 26);
            gfx.PutPixel(15 + x, 13 + y, 208, 42, 24);
            gfx.PutPixel(16 + x, 13 + y, 194, 42, 22);
            gfx.PutPixel(17 + x, 13 + y, 177, 40, 20);
            gfx.PutPixel(18 + x, 13 + y, 158, 38, 17);
            gfx.PutPixel(19 + x, 13 + y, 135, 34, 14);
            gfx.PutPixel(20 + x, 13 + y, 110, 28, 11);
            gfx.PutPixel(21 + x, 13 + y, 82, 22, 8);
            gfx.PutPixel(22 + x, 13 + y, 51, 14, 5);
            gfx.PutPixel(23 + x, 13 + y, 46, 5, 2);
            gfx.PutPixel(0 + x, 14 + y, 75, 2, 2);
            gfx.PutPixel(1 + x, 14 + y, 36, 10, 4);
            gfx.PutPixel(2 + x, 14 + y, 68, 18, 7);
            gfx.PutPixel(3 + x, 14 + y, 97, 25, 9);
            gfx.PutPixel(4 + x, 14 + y, 122, 31, 13);
            gfx.PutPixel(5 + x, 14 + y, 145, 36, 15);
            gfx.PutPixel(6 + x, 14 + y, 166, 39, 18);
            gfx.PutPixel(7 + x, 14 + y, 183, 41, 20);
            gfx.PutPixel(8 + x, 14 + y, 197, 42, 22);
            gfx.PutPixel(9 + x, 14 + y, 208, 42, 24);
            gfx.PutPixel(10 + x, 14 + y, 216, 41, 25);
            gfx.PutPixel(11 + x, 14 + y, 220, 40, 26);
            gfx.PutPixel(12 + x, 14 + y, 220, 40, 26);
            gfx.PutPixel(13 + x, 14 + y, 218, 41, 26);
            gfx.PutPixel(14 + x, 14 + y, 211, 42, 25);
            gfx.PutPixel(15 + x, 14 + y, 202, 42, 23);
            gfx.PutPixel(16 + x, 14 + y, 188, 42, 21);
            gfx.PutPixel(17 + x, 14 + y, 172, 40, 19);
            gfx.PutPixel(18 + x, 14 + y, 152, 37, 16);
            gfx.PutPixel(19 + x, 14 + y, 130, 33, 14);
            gfx.PutPixel(20 + x, 14 + y, 105, 27, 11);
            gfx.PutPixel(21 + x, 14 + y, 77, 21, 7);
            gfx.PutPixel(22 + x, 14 + y, 46, 13, 5);
            gfx.PutPixel(23 + x, 14 + y, 65, 4, 3);
            gfx.PutPixel(0 + x, 15 + y, 71, 0, 0);
            gfx.PutPixel(1 + x, 15 + y, 28, 8, 2);
            gfx.PutPixel(2 + x, 15 + y, 59, 16, 6);
            gfx.PutPixel(3 + x, 15 + y, 87, 23, 8);
            gfx.PutPixel(4 + x, 15 + y, 112, 28, 11);
            gfx.PutPixel(5 + x, 15 + y, 135, 33, 13);
            gfx.PutPixel(6 + x, 15 + y, 155, 36, 16);
            gfx.PutPixel(7 + x, 15 + y, 172, 39, 18);
            gfx.PutPixel(8 + x, 15 + y, 187, 40, 20);
            gfx.PutPixel(9 + x, 15 + y, 197, 41, 22);
            gfx.PutPixel(10 + x, 15 + y, 205, 41, 23);
            gfx.PutPixel(11 + x, 15 + y, 209, 41, 24);
            gfx.PutPixel(12 + x, 15 + y, 210, 41, 24);
            gfx.PutPixel(13 + x, 15 + y, 207, 41, 24);
            gfx.PutPixel(14 + x, 15 + y, 201, 42, 23);
            gfx.PutPixel(15 + x, 15 + y, 192, 42, 22);
            gfx.PutPixel(16 + x, 15 + y, 179, 41, 20);
            gfx.PutPixel(17 + x, 15 + y, 163, 39, 18);
            gfx.PutPixel(18 + x, 15 + y, 144, 36, 15);
            gfx.PutPixel(19 + x, 15 + y, 121, 31, 13);
            gfx.PutPixel(20 + x, 15 + y, 96, 26, 10);
            gfx.PutPixel(21 + x, 15 + y, 69, 19, 7);
            gfx.PutPixel(22 + x, 15 + y, 37, 10, 4);
            gfx.PutPixel(23 + x, 15 + y, 79, 4, 4);
            gfx.PutPixel(1 + x, 16 + y, 36, 5, 1);
            gfx.PutPixel(2 + x, 16 + y, 47, 12, 4);
            gfx.PutPixel(3 + x, 16 + y, 75, 19, 6);
            gfx.PutPixel(4 + x, 16 + y, 101, 25, 9);
            gfx.PutPixel(5 + x, 16 + y, 123, 30, 11);
            gfx.PutPixel(6 + x, 16 + y, 142, 34, 13);
            gfx.PutPixel(7 + x, 16 + y, 159, 37, 15);
            gfx.PutPixel(8 + x, 16 + y, 173, 38, 18);
            gfx.PutPixel(9 + x, 16 + y, 183, 40, 19);
            gfx.PutPixel(10 + x, 16 + y, 191, 40, 21);
            gfx.PutPixel(11 + x, 16 + y, 195, 41, 21);
            gfx.PutPixel(12 + x, 16 + y, 196, 41, 22);
            gfx.PutPixel(13 + x, 16 + y, 194, 41, 21);
            gfx.PutPixel(14 + x, 16 + y, 189, 41, 21);
            gfx.PutPixel(15 + x, 16 + y, 179, 41, 20);
            gfx.PutPixel(16 + x, 16 + y, 167, 39, 18);
            gfx.PutPixel(17 + x, 16 + y, 151, 37, 17);
            gfx.PutPixel(18 + x, 16 + y, 132, 34, 14);
            gfx.PutPixel(19 + x, 16 + y, 110, 28, 11);
            gfx.PutPixel(20 + x, 16 + y, 85, 23, 9);
            gfx.PutPixel(21 + x, 16 + y, 57, 16, 6);
            gfx.PutPixel(22 + x, 16 + y, 28, 7, 3);
            gfx.PutPixel(23 + x, 16 + y, 97, 2, 2);
            gfx.PutPixel(1 + x, 17 + y, 73, 0, 0);
            gfx.PutPixel(2 + x, 17 + y, 32, 9, 3);
            gfx.PutPixel(3 + x, 17 + y, 61, 16, 5);
            gfx.PutPixel(4 + x, 17 + y, 85, 22, 7);
            gfx.PutPixel(5 + x, 17 + y, 108, 27, 10);
            gfx.PutPixel(6 + x, 17 + y, 127, 31, 12);
            gfx.PutPixel(7 + x, 17 + y, 143, 34, 14);
            gfx.PutPixel(8 + x, 17 + y, 157, 36, 15);
            gfx.PutPixel(9 + x, 17 + y, 168, 38, 17);
            gfx.PutPixel(10 + x, 17 + y, 175, 39, 18);
            gfx.PutPixel(11 + x, 17 + y, 179, 40, 19);
            gfx.PutPixel(12 + x, 17 + y, 181, 40, 19);
            gfx.PutPixel(13 + x, 17 + y, 178, 40, 19);
            gfx.PutPixel(14 + x, 17 + y, 173, 40, 19);
            gfx.PutPixel(15 + x, 17 + y, 163, 39, 18);
            gfx.PutPixel(16 + x, 17 + y, 152, 37, 17);
            gfx.PutPixel(17 + x, 17 + y, 136, 34, 15);
            gfx.PutPixel(18 + x, 17 + y, 117, 30, 12);
            gfx.PutPixel(19 + x, 17 + y, 95, 25, 10);
            gfx.PutPixel(20 + x, 17 + y, 70, 19, 8);
            gfx.PutPixel(21 + x, 17 + y, 43, 12, 4);
            gfx.PutPixel(22 + x, 17 + y, 69, 6, 4);
            gfx.PutPixel(2 + x, 18 + y, 61, 3, 1);
            gfx.PutPixel(3 + x, 18 + y, 43, 12, 4);
            gfx.PutPixel(4 + x, 18 + y, 68, 17, 6);
            gfx.PutPixel(5 + x, 18 + y, 90, 23, 8);
            gfx.PutPixel(6 + x, 18 + y, 109, 27, 10);
            gfx.PutPixel(7 + x, 18 + y, 125, 31, 11);
            gfx.PutPixel(8 + x, 18 + y, 138, 33, 13);
            gfx.PutPixel(9 + x, 18 + y, 149, 34, 14);
            gfx.PutPixel(10 + x, 18 + y, 156, 36, 15);
            gfx.PutPixel(11 + x, 18 + y, 161, 37, 16);
            gfx.PutPixel(12 + x, 18 + y, 161, 38, 17);
            gfx.PutPixel(13 + x, 18 + y, 160, 37, 16);
            gfx.PutPixel(14 + x, 18 + y, 154, 37, 17);
            gfx.PutPixel(15 + x, 18 + y, 146, 36, 15);
            gfx.PutPixel(16 + x, 18 + y, 133, 33, 14);
            gfx.PutPixel(17 + x, 18 + y, 118, 30, 12);
            gfx.PutPixel(18 + x, 18 + y, 100, 27, 10);
            gfx.PutPixel(19 + x, 18 + y, 78, 22, 8);
            gfx.PutPixel(20 + x, 18 + y, 53, 15, 5);
            gfx.PutPixel(21 + x, 18 + y, 47, 8, 4);
            gfx.PutPixel(22 + x, 18 + y, 116, 10, 10);
            gfx.PutPixel(2 + x, 19 + y, 72, 0, 0);
            gfx.PutPixel(3 + x, 19 + y, 40, 6, 2);
            gfx.PutPixel(4 + x, 19 + y, 48, 13, 4);
            gfx.PutPixel(5 + x, 19 + y, 70, 18, 6);
            gfx.PutPixel(6 + x, 19 + y, 89, 22, 8);
            gfx.PutPixel(7 + x, 19 + y, 105, 26, 9);
            gfx.PutPixel(8 + x, 19 + y, 118, 29, 11);
            gfx.PutPixel(9 + x, 19 + y, 128, 31, 12);
            gfx.PutPixel(10 + x, 19 + y, 135, 33, 13);
            gfx.PutPixel(11 + x, 19 + y, 139, 33, 13);
            gfx.PutPixel(12 + x, 19 + y, 141, 34, 14);
            gfx.PutPixel(13 + x, 19 + y, 138, 34, 14);
            gfx.PutPixel(14 + x, 19 + y, 133, 34, 14);
            gfx.PutPixel(15 + x, 19 + y, 125, 32, 13);
            gfx.PutPixel(16 + x, 19 + y, 112, 30, 12);
            gfx.PutPixel(17 + x, 19 + y, 98, 26, 10);
            gfx.PutPixel(18 + x, 19 + y, 79, 22, 8);
            gfx.PutPixel(19 + x, 19 + y, 57, 16, 6);
            gfx.PutPixel(20 + x, 19 + y, 35, 9, 4);
            gfx.PutPixel(21 + x, 19 + y, 97, 6, 6);
            gfx.PutPixel(3 + x, 20 + y, 75, 0, 0);
            gfx.PutPixel(4 + x, 20 + y, 40, 7, 2);
            gfx.PutPixel(5 + x, 20 + y, 48, 13, 4);
            gfx.PutPixel(6 + x, 20 + y, 66, 17, 6);
            gfx.PutPixel(7 + x, 20 + y, 82, 21, 7);
            gfx.PutPixel(8 + x, 20 + y, 95, 24, 8);
            gfx.PutPixel(9 + x, 20 + y, 105, 26, 9);
            gfx.PutPixel(10 + x, 20 + y, 112, 27, 10);
            gfx.PutPixel(11 + x, 20 + y, 116, 29, 11);
            gfx.PutPixel(12 + x, 20 + y, 117, 29, 11);
            gfx.PutPixel(13 + x, 20 + y, 115, 29, 11);
            gfx.PutPixel(14 + x, 20 + y, 109, 28, 11);
            gfx.PutPixel(15 + x, 20 + y, 101, 27, 11);
            gfx.PutPixel(16 + x, 20 + y, 89, 23, 9);
            gfx.PutPixel(17 + x, 20 + y, 74, 20, 8);
            gfx.PutPixel(18 + x, 20 + y, 56, 16, 5);
            gfx.PutPixel(19 + x, 20 + y, 37, 9, 4);
            gfx.PutPixel(20 + x, 20 + y, 82, 7, 5);
            gfx.PutPixel(4 + x, 21 + y, 84, 0, 0);
            gfx.PutPixel(5 + x, 21 + y, 64, 4, 1);
            gfx.PutPixel(6 + x, 21 + y, 41, 11, 3);
            gfx.PutPixel(7 + x, 21 + y, 57, 15, 5);
            gfx.PutPixel(8 + x, 21 + y, 70, 18, 6);
            gfx.PutPixel(9 + x, 21 + y, 79, 20, 7);
            gfx.PutPixel(10 + x, 21 + y, 86, 22, 7);
            gfx.PutPixel(11 + x, 21 + y, 90, 23, 8);
            gfx.PutPixel(12 + x, 21 + y, 91, 24, 8);
            gfx.PutPixel(13 + x, 21 + y, 89, 23, 9);
            gfx.PutPixel(14 + x, 21 + y, 83, 22, 8);
            gfx.PutPixel(15 + x, 21 + y, 75, 20, 7);
            gfx.PutPixel(16 + x, 21 + y, 63, 17, 6);
            gfx.PutPixel(17 + x, 21 + y, 48, 13, 5);
            gfx.PutPixel(18 + x, 21 + y, 57, 9, 4);
            gfx.PutPixel(19 + x, 21 + y, 101, 5, 5);
            gfx.PutPixel(6 + x, 22 + y, 80, 2, 0);
            gfx.PutPixel(7 + x, 22 + y, 41, 7, 2);
            gfx.PutPixel(8 + x, 22 + y, 42, 11, 3);
            gfx.PutPixel(9 + x, 22 + y, 52, 14, 4);
            gfx.PutPixel(10 + x, 22 + y, 58, 15, 5);
            gfx.PutPixel(11 + x, 22 + y, 62, 16, 5);
            gfx.PutPixel(12 + x, 22 + y, 63, 16, 5);
            gfx.PutPixel(13 + x, 22 + y, 60, 16, 6);
            gfx.PutPixel(14 + x, 22 + y, 55, 15, 5);
            gfx.PutPixel(15 + x, 22 + y, 46, 13, 5);
            gfx.PutPixel(16 + x, 22 + y, 38, 9, 4);
            gfx.PutPixel(17 + x, 22 + y, 80, 6, 5);
            gfx.PutPixel(18 + x, 22 + y, 115, 0, 0);
            gfx.PutPixel(7 + x, 23 + y, 51, 0, 0);
            gfx.PutPixel(8 + x, 23 + y, 87, 3, 0);
            gfx.PutPixel(9 + x, 23 + y, 81, 3, 1);
            gfx.PutPixel(10 + x, 23 + y, 72, 6, 2);
            gfx.PutPixel(11 + x, 23 + y, 57, 7, 2);
            gfx.PutPixel(12 + x, 23 + y, 52, 8, 3);
            gfx.PutPixel(13 + x, 23 + y, 72, 7, 3);
            gfx.PutPixel(14 + x, 23 + y, 83, 7, 4);
            gfx.PutPixel(15 + x, 23 + y, 93, 4, 4);
            gfx.PutPixel(16 + x, 23 + y, 104, 0, 0);

    }
    else if (type == 'b')
    {
            gfx.PutPixel(7 + x, 0 + y, 7, 92, 113);
            gfx.PutPixel(8 + x, 0 + y, 8, 82, 102);
            gfx.PutPixel(9 + x, 0 + y, 5, 70, 91);
            gfx.PutPixel(10 + x, 0 + y, 5, 55, 73);
            gfx.PutPixel(11 + x, 0 + y, 3, 34, 49);
            gfx.PutPixel(12 + x, 0 + y, 3, 29, 43);
            gfx.PutPixel(13 + x, 0 + y, 3, 48, 66);
            gfx.PutPixel(14 + x, 0 + y, 2, 59, 80);
            gfx.PutPixel(15 + x, 0 + y, 1, 72, 91);
            gfx.PutPixel(16 + x, 0 + y, 0, 79, 96);
            gfx.PutPixel(6 + x, 1 + y, 9, 78, 98);
            gfx.PutPixel(7 + x, 1 + y, 5, 32, 46);
            gfx.PutPixel(8 + x, 1 + y, 5, 34, 53);
            gfx.PutPixel(9 + x, 1 + y, 5, 40, 62);
            gfx.PutPixel(10 + x, 1 + y, 5, 43, 68);
            gfx.PutPixel(11 + x, 1 + y, 5, 46, 72);
            gfx.PutPixel(12 + x, 1 + y, 6, 48, 73);
            gfx.PutPixel(13 + x, 1 + y, 4, 44, 70);
            gfx.PutPixel(14 + x, 1 + y, 4, 39, 62);
            gfx.PutPixel(15 + x, 1 + y, 3, 33, 52);
            gfx.PutPixel(16 + x, 1 + y, 2, 25, 39);
            gfx.PutPixel(17 + x, 1 + y, 0, 54, 70);
            gfx.PutPixel(18 + x, 1 + y, 0, 82, 105);
            gfx.PutPixel(4 + x, 2 + y, 13, 93, 116);
            gfx.PutPixel(5 + x, 2 + y, 7, 56, 73);
            gfx.PutPixel(6 + x, 2 + y, 6, 35, 52);
            gfx.PutPixel(7 + x, 2 + y, 7, 45, 70);
            gfx.PutPixel(8 + x, 2 + y, 8, 55, 84);
            gfx.PutPixel(9 + x, 2 + y, 9, 63, 95);
            gfx.PutPixel(10 + x, 2 + y, 9, 67, 100);
            gfx.PutPixel(11 + x, 2 + y, 8, 67, 103);
            gfx.PutPixel(12 + x, 2 + y, 7, 66, 102);
            gfx.PutPixel(13 + x, 2 + y, 7, 64, 99);
            gfx.PutPixel(14 + x, 2 + y, 5, 58, 91);
            gfx.PutPixel(15 + x, 2 + y, 6, 54, 82);
            gfx.PutPixel(16 + x, 2 + y, 3, 43, 69);
            gfx.PutPixel(17 + x, 2 + y, 2, 32, 53);
            gfx.PutPixel(18 + x, 2 + y, 2, 34, 48);
            gfx.PutPixel(19 + x, 2 + y, 0, 73, 90);
            gfx.PutPixel(3 + x, 3 + y, 12, 87, 105);
            gfx.PutPixel(4 + x, 3 + y, 5, 31, 44);
            gfx.PutPixel(5 + x, 3 + y, 6, 38, 60);
            gfx.PutPixel(6 + x, 3 + y, 8, 53, 81);
            gfx.PutPixel(7 + x, 3 + y, 10, 65, 99);
            gfx.PutPixel(8 + x, 3 + y, 11, 76, 113);
            gfx.PutPixel(9 + x, 3 + y, 11, 82, 123);
            gfx.PutPixel(10 + x, 3 + y, 12, 87, 129);
            gfx.PutPixel(11 + x, 3 + y, 11, 87, 131);
            gfx.PutPixel(12 + x, 3 + y, 10, 86, 130);
            gfx.PutPixel(13 + x, 3 + y, 8, 81, 126);
            gfx.PutPixel(14 + x, 3 + y, 7, 77, 118);
            gfx.PutPixel(15 + x, 3 + y, 7, 70, 108);
            gfx.PutPixel(16 + x, 3 + y, 5, 60, 95);
            gfx.PutPixel(17 + x, 3 + y, 4, 49, 79);
            gfx.PutPixel(18 + x, 3 + y, 3, 38, 61);
            gfx.PutPixel(19 + x, 3 + y, 2, 25, 39);
            gfx.PutPixel(20 + x, 3 + y, 0, 55, 71);
            gfx.PutPixel(2 + x, 4 + y, 13, 93, 107);
            gfx.PutPixel(3 + x, 4 + y, 5, 33, 45);
            gfx.PutPixel(4 + x, 4 + y, 7, 40, 61);
            gfx.PutPixel(5 + x, 4 + y, 10, 58, 87);
            gfx.PutPixel(6 + x, 4 + y, 11, 71, 107);
            gfx.PutPixel(7 + x, 4 + y, 14, 86, 126);
            gfx.PutPixel(8 + x, 4 + y, 14, 93, 139);
            gfx.PutPixel(9 + x, 4 + y, 15, 101, 149);
            gfx.PutPixel(10 + x, 4 + y, 14, 104, 154);
            gfx.PutPixel(11 + x, 4 + y, 14, 106, 157);
            gfx.PutPixel(12 + x, 4 + y, 13, 105, 156);
            gfx.PutPixel(13 + x, 4 + y, 12, 100, 150);
            gfx.PutPixel(14 + x, 4 + y, 9, 93, 142);
            gfx.PutPixel(15 + x, 4 + y, 8, 87, 132);
            gfx.PutPixel(16 + x, 4 + y, 7, 77, 119);
            gfx.PutPixel(17 + x, 4 + y, 6, 66, 102);
            gfx.PutPixel(18 + x, 4 + y, 4, 53, 83);
            gfx.PutPixel(19 + x, 4 + y, 3, 38, 60);
            gfx.PutPixel(20 + x, 4 + y, 2, 22, 36);
            gfx.PutPixel(21 + x, 4 + y, 0, 70, 88);
            gfx.PutPixel(2 + x, 5 + y, 8, 58, 74);
            gfx.PutPixel(3 + x, 5 + y, 7, 36, 55);
            gfx.PutPixel(4 + x, 5 + y, 9, 55, 84);
            gfx.PutPixel(5 + x, 5 + y, 13, 75, 110);
            gfx.PutPixel(6 + x, 5 + y, 16, 91, 133);
            gfx.PutPixel(7 + x, 5 + y, 16, 100, 149);
            gfx.PutPixel(8 + x, 5 + y, 17, 111, 162);
            gfx.PutPixel(9 + x, 5 + y, 17, 118, 172);
            gfx.PutPixel(10 + x, 5 + y, 17, 122, 177);
            gfx.PutPixel(11 + x, 5 + y, 15, 123, 180);
            gfx.PutPixel(12 + x, 5 + y, 15, 123, 178);
            gfx.PutPixel(13 + x, 5 + y, 14, 119, 173);
            gfx.PutPixel(14 + x, 5 + y, 12, 111, 164);
            gfx.PutPixel(15 + x, 5 + y, 11, 103, 154);
            gfx.PutPixel(16 + x, 5 + y, 9, 94, 140);
            gfx.PutPixel(17 + x, 5 + y, 7, 80, 123);
            gfx.PutPixel(18 + x, 5 + y, 5, 65, 102);
            gfx.PutPixel(19 + x, 5 + y, 5, 52, 81);
            gfx.PutPixel(20 + x, 5 + y, 3, 36, 57);
            gfx.PutPixel(21 + x, 5 + y, 1, 28, 42);
            gfx.PutPixel(22 + x, 5 + y, 0, 84, 103);
            gfx.PutPixel(1 + x, 6 + y, 7, 74, 92);
            gfx.PutPixel(2 + x, 6 + y, 4, 25, 40);
            gfx.PutPixel(3 + x, 6 + y, 8, 48, 73);
            gfx.PutPixel(4 + x, 6 + y, 11, 68, 103);
            gfx.PutPixel(5 + x, 6 + y, 16, 90, 130);
            gfx.PutPixel(6 + x, 6 + y, 18, 104, 153);
            gfx.PutPixel(7 + x, 6 + y, 20, 118, 171);
            gfx.PutPixel(8 + x, 6 + y, 19, 127, 184);
            gfx.PutPixel(9 + x, 6 + y, 21, 136, 193);
            gfx.PutPixel(10 + x, 6 + y, 20, 139, 198);
            gfx.PutPixel(11 + x, 6 + y, 19, 142, 200);
            gfx.PutPixel(12 + x, 6 + y, 17, 139, 197);
            gfx.PutPixel(13 + x, 6 + y, 16, 134, 192);
            gfx.PutPixel(14 + x, 6 + y, 14, 127, 184);
            gfx.PutPixel(15 + x, 6 + y, 12, 118, 173);
            gfx.PutPixel(16 + x, 6 + y, 11, 106, 159);
            gfx.PutPixel(17 + x, 6 + y, 7, 91, 140);
            gfx.PutPixel(18 + x, 6 + y, 6, 79, 122);
            gfx.PutPixel(19 + x, 6 + y, 5, 64, 99);
            gfx.PutPixel(20 + x, 6 + y, 3, 46, 73);
            gfx.PutPixel(21 + x, 6 + y, 2, 27, 45);
            gfx.PutPixel(22 + x, 6 + y, 0, 47, 60);
            gfx.PutPixel(1 + x, 7 + y, 3, 28, 37);
            gfx.PutPixel(2 + x, 7 + y, 5, 35, 55);
            gfx.PutPixel(3 + x, 7 + y, 8, 56, 87);
            gfx.PutPixel(4 + x, 7 + y, 12, 79, 118);
            gfx.PutPixel(5 + x, 7 + y, 16, 97, 144);
            gfx.PutPixel(6 + x, 7 + y, 18, 114, 167);
            gfx.PutPixel(7 + x, 7 + y, 22, 133, 187);
            gfx.PutPixel(8 + x, 7 + y, 24, 145, 201);
            gfx.PutPixel(9 + x, 7 + y, 24, 151, 210);
            gfx.PutPixel(10 + x, 7 + y, 22, 154, 215);
            gfx.PutPixel(11 + x, 7 + y, 21, 157, 217);
            gfx.PutPixel(12 + x, 7 + y, 20, 154, 214);
            gfx.PutPixel(13 + x, 7 + y, 18, 150, 209);
            gfx.PutPixel(14 + x, 7 + y, 17, 141, 200);
            gfx.PutPixel(15 + x, 7 + y, 13, 130, 188);
            gfx.PutPixel(16 + x, 7 + y, 11, 117, 173);
            gfx.PutPixel(17 + x, 7 + y, 10, 106, 157);
            gfx.PutPixel(18 + x, 7 + y, 7, 88, 135);
            gfx.PutPixel(19 + x, 7 + y, 6, 73, 113);
            gfx.PutPixel(20 + x, 7 + y, 5, 55, 88);
            gfx.PutPixel(21 + x, 7 + y, 3, 36, 58);
            gfx.PutPixel(22 + x, 7 + y, 2, 18, 29);
            gfx.PutPixel(23 + x, 7 + y, 0, 74, 91);
            gfx.PutPixel(0 + x, 8 + y, 5, 72, 88);
            gfx.PutPixel(1 + x, 8 + y, 2, 19, 32);
            gfx.PutPixel(2 + x, 8 + y, 6, 45, 69);
            gfx.PutPixel(3 + x, 8 + y, 9, 65, 100);
            gfx.PutPixel(4 + x, 8 + y, 12, 86, 129);
            gfx.PutPixel(5 + x, 8 + y, 16, 106, 155);
            gfx.PutPixel(6 + x, 8 + y, 20, 125, 178);
            gfx.PutPixel(7 + x, 8 + y, 22, 142, 199);
            gfx.PutPixel(8 + x, 8 + y, 25, 155, 214);
            gfx.PutPixel(9 + x, 8 + y, 26, 165, 225);
            gfx.PutPixel(10 + x, 8 + y, 26, 170, 229);
            gfx.PutPixel(11 + x, 8 + y, 25, 173, 231);
            gfx.PutPixel(12 + x, 8 + y, 23, 171, 229);
            gfx.PutPixel(13 + x, 8 + y, 20, 164, 222);
            gfx.PutPixel(14 + x, 8 + y, 18, 155, 214);
            gfx.PutPixel(15 + x, 8 + y, 15, 142, 201);
            gfx.PutPixel(16 + x, 8 + y, 14, 130, 186);
            gfx.PutPixel(17 + x, 8 + y, 11, 114, 169);
            gfx.PutPixel(18 + x, 8 + y, 9, 98, 148);
            gfx.PutPixel(19 + x, 8 + y, 7, 83, 126);
            gfx.PutPixel(20 + x, 8 + y, 5, 64, 100);
            gfx.PutPixel(21 + x, 8 + y, 4, 45, 71);
            gfx.PutPixel(22 + x, 8 + y, 2, 25, 41);
            gfx.PutPixel(23 + x, 8 + y, 0, 62, 78);
            gfx.PutPixel(0 + x, 9 + y, 5, 71, 88);
            gfx.PutPixel(1 + x, 9 + y, 4, 27, 40);
            gfx.PutPixel(2 + x, 9 + y, 7, 49, 76);
            gfx.PutPixel(3 + x, 9 + y, 10, 72, 108);
            gfx.PutPixel(4 + x, 9 + y, 13, 92, 137);
            gfx.PutPixel(5 + x, 9 + y, 17, 112, 163);
            gfx.PutPixel(6 + x, 9 + y, 19, 130, 187);
            gfx.PutPixel(7 + x, 9 + y, 23, 147, 206);
            gfx.PutPixel(8 + x, 9 + y, 24, 162, 223);
            gfx.PutPixel(9 + x, 9 + y, 25, 171, 233);
            gfx.PutPixel(10 + x, 9 + y, 26, 180, 238);
            gfx.PutPixel(11 + x, 9 + y, 25, 183, 241);
            gfx.PutPixel(12 + x, 9 + y, 23, 181, 239);
            gfx.PutPixel(13 + x, 9 + y, 23, 176, 233);
            gfx.PutPixel(14 + x, 9 + y, 19, 165, 224);
            gfx.PutPixel(15 + x, 9 + y, 18, 154, 212);
            gfx.PutPixel(16 + x, 9 + y, 15, 140, 197);
            gfx.PutPixel(17 + x, 9 + y, 13, 124, 178);
            gfx.PutPixel(18 + x, 9 + y, 9, 105, 158);
            gfx.PutPixel(19 + x, 9 + y, 8, 87, 134);
            gfx.PutPixel(20 + x, 9 + y, 5, 69, 109);
            gfx.PutPixel(21 + x, 9 + y, 3, 49, 79);
            gfx.PutPixel(22 + x, 9 + y, 3, 32, 49);
            gfx.PutPixel(23 + x, 9 + y, 0, 50, 64);
            gfx.PutPixel(0 + x, 10 + y, 4, 60, 74);
            gfx.PutPixel(1 + x, 10 + y, 3, 28, 46);
            gfx.PutPixel(2 + x, 10 + y, 7, 52, 81);
            gfx.PutPixel(3 + x, 10 + y, 10, 75, 112);
            gfx.PutPixel(4 + x, 10 + y, 12, 93, 140);
            gfx.PutPixel(5 + x, 10 + y, 16, 114, 167);
            gfx.PutPixel(6 + x, 10 + y, 18, 133, 190);
            gfx.PutPixel(7 + x, 10 + y, 21, 150, 210);
            gfx.PutPixel(8 + x, 10 + y, 23, 164, 226);
            gfx.PutPixel(9 + x, 10 + y, 26, 178, 237);
            gfx.PutPixel(10 + x, 10 + y, 26, 187, 244);
            gfx.PutPixel(11 + x, 10 + y, 26, 193, 247);
            gfx.PutPixel(12 + x, 10 + y, 24, 191, 245);
            gfx.PutPixel(13 + x, 10 + y, 23, 185, 240);
            gfx.PutPixel(14 + x, 10 + y, 20, 171, 229);
            gfx.PutPixel(15 + x, 10 + y, 18, 157, 217);
            gfx.PutPixel(16 + x, 10 + y, 15, 143, 202);
            gfx.PutPixel(17 + x, 10 + y, 14, 129, 185);
            gfx.PutPixel(18 + x, 10 + y, 10, 110, 165);
            gfx.PutPixel(19 + x, 10 + y, 9, 93, 141);
            gfx.PutPixel(20 + x, 10 + y, 7, 76, 116);
            gfx.PutPixel(21 + x, 10 + y, 4, 54, 86);
            gfx.PutPixel(22 + x, 10 + y, 2, 33, 54);
            gfx.PutPixel(23 + x, 10 + y, 0, 31, 45);
            gfx.PutPixel(0 + x, 11 + y, 3, 42, 53);
            gfx.PutPixel(1 + x, 11 + y, 4, 31, 49);
            gfx.PutPixel(2 + x, 11 + y, 5, 51, 83);
            gfx.PutPixel(3 + x, 11 + y, 9, 74, 113);
            gfx.PutPixel(4 + x, 11 + y, 12, 95, 143);
            gfx.PutPixel(5 + x, 11 + y, 16, 117, 169);
            gfx.PutPixel(6 + x, 11 + y, 18, 133, 191);
            gfx.PutPixel(7 + x, 11 + y, 19, 150, 210);
            gfx.PutPixel(8 + x, 11 + y, 23, 166, 226);
            gfx.PutPixel(9 + x, 11 + y, 25, 180, 238);
            gfx.PutPixel(10 + x, 11 + y, 25, 190, 246);
            gfx.PutPixel(11 + x, 11 + y, 25, 198, 248);
            gfx.PutPixel(12 + x, 11 + y, 24, 198, 248);
            gfx.PutPixel(13 + x, 11 + y, 22, 189, 243);
            gfx.PutPixel(14 + x, 11 + y, 22, 178, 234);
            gfx.PutPixel(15 + x, 11 + y, 18, 161, 221);
            gfx.PutPixel(16 + x, 11 + y, 16, 148, 207);
            gfx.PutPixel(17 + x, 11 + y, 14, 132, 189);
            gfx.PutPixel(18 + x, 11 + y, 11, 114, 168);
            gfx.PutPixel(19 + x, 11 + y, 9, 97, 145);
            gfx.PutPixel(20 + x, 11 + y, 7, 78, 119);
            gfx.PutPixel(21 + x, 11 + y, 5, 57, 90);
            gfx.PutPixel(22 + x, 11 + y, 4, 37, 58);
            gfx.PutPixel(23 + x, 11 + y, 1, 14, 24);
            gfx.PutPixel(0 + x, 12 + y, 2, 44, 55);
            gfx.PutPixel(1 + x, 12 + y, 4, 31, 49);
            gfx.PutPixel(2 + x, 12 + y, 5, 51, 81);
            gfx.PutPixel(3 + x, 12 + y, 9, 75, 113);
            gfx.PutPixel(4 + x, 12 + y, 10, 91, 139);
            gfx.PutPixel(5 + x, 12 + y, 14, 114, 166);
            gfx.PutPixel(6 + x, 12 + y, 15, 129, 187);
            gfx.PutPixel(7 + x, 12 + y, 18, 147, 207);
            gfx.PutPixel(8 + x, 12 + y, 20, 163, 222);
            gfx.PutPixel(9 + x, 12 + y, 22, 176, 234);
            gfx.PutPixel(10 + x, 12 + y, 24, 187, 242);
            gfx.PutPixel(11 + x, 12 + y, 24, 195, 245);
            gfx.PutPixel(12 + x, 12 + y, 24, 197, 246);
            gfx.PutPixel(13 + x, 12 + y, 22, 187, 241);
            gfx.PutPixel(14 + x, 12 + y, 22, 178, 234);
            gfx.PutPixel(15 + x, 12 + y, 19, 162, 222);
            gfx.PutPixel(16 + x, 12 + y, 16, 147, 207);
            gfx.PutPixel(17 + x, 12 + y, 15, 133, 190);
            gfx.PutPixel(18 + x, 12 + y, 11, 113, 169);
            gfx.PutPixel(19 + x, 12 + y, 10, 96, 145);
            gfx.PutPixel(20 + x, 12 + y, 7, 77, 118);
            gfx.PutPixel(21 + x, 12 + y, 5, 57, 90);
            gfx.PutPixel(22 + x, 12 + y, 3, 35, 57);
            gfx.PutPixel(23 + x, 12 + y, 1, 17, 26);
            gfx.PutPixel(0 + x, 13 + y, 1, 57, 71);
            gfx.PutPixel(1 + x, 13 + y, 2, 27, 45);
            gfx.PutPixel(2 + x, 13 + y, 4, 47, 77);
            gfx.PutPixel(3 + x, 13 + y, 8, 70, 108);
            gfx.PutPixel(4 + x, 13 + y, 10, 91, 137);
            gfx.PutPixel(5 + x, 13 + y, 12, 108, 160);
            gfx.PutPixel(6 + x, 13 + y, 14, 125, 181);
            gfx.PutPixel(7 + x, 13 + y, 16, 143, 202);
            gfx.PutPixel(8 + x, 13 + y, 19, 157, 217);
            gfx.PutPixel(9 + x, 13 + y, 20, 168, 228);
            gfx.PutPixel(10 + x, 13 + y, 23, 181, 237);
            gfx.PutPixel(11 + x, 13 + y, 22, 185, 240);
            gfx.PutPixel(12 + x, 13 + y, 22, 185, 240);
            gfx.PutPixel(13 + x, 13 + y, 21, 181, 237);
            gfx.PutPixel(14 + x, 13 + y, 20, 171, 229);
            gfx.PutPixel(15 + x, 13 + y, 18, 159, 219);
            gfx.PutPixel(16 + x, 13 + y, 16, 144, 203);
            gfx.PutPixel(17 + x, 13 + y, 15, 130, 186);
            gfx.PutPixel(18 + x, 13 + y, 12, 112, 166);
            gfx.PutPixel(19 + x, 13 + y, 10, 94, 142);
            gfx.PutPixel(20 + x, 13 + y, 8, 76, 115);
            gfx.PutPixel(21 + x, 13 + y, 5, 55, 86);
            gfx.PutPixel(22 + x, 13 + y, 3, 33, 53);
            gfx.PutPixel(23 + x, 13 + y, 0, 35, 48);
            gfx.PutPixel(0 + x, 14 + y, 0, 64, 81);
            gfx.PutPixel(1 + x, 14 + y, 2, 23, 37);
            gfx.PutPixel(2 + x, 14 + y, 5, 47, 72);
            gfx.PutPixel(3 + x, 14 + y, 6, 66, 102);
            gfx.PutPixel(4 + x, 14 + y, 9, 85, 128);
            gfx.PutPixel(5 + x, 14 + y, 10, 101, 152);
            gfx.PutPixel(6 + x, 14 + y, 13, 119, 174);
            gfx.PutPixel(7 + x, 14 + y, 14, 133, 192);
            gfx.PutPixel(8 + x, 14 + y, 16, 147, 207);
            gfx.PutPixel(9 + x, 14 + y, 18, 159, 219);
            gfx.PutPixel(10 + x, 14 + y, 19, 167, 227);
            gfx.PutPixel(11 + x, 14 + y, 20, 174, 231);
            gfx.PutPixel(12 + x, 14 + y, 20, 174, 231);
            gfx.PutPixel(13 + x, 14 + y, 20, 171, 229);
            gfx.PutPixel(14 + x, 14 + y, 19, 162, 222);
            gfx.PutPixel(15 + x, 14 + y, 17, 153, 213);
            gfx.PutPixel(16 + x, 14 + y, 15, 138, 197);
            gfx.PutPixel(17 + x, 14 + y, 13, 124, 180);
            gfx.PutPixel(18 + x, 14 + y, 12, 107, 160);
            gfx.PutPixel(19 + x, 14 + y, 10, 91, 137);
            gfx.PutPixel(20 + x, 14 + y, 8, 73, 110);
            gfx.PutPixel(21 + x, 14 + y, 4, 50, 80);
            gfx.PutPixel(22 + x, 14 + y, 4, 31, 49);
            gfx.PutPixel(23 + x, 14 + y, 1, 52, 69);
            gfx.PutPixel(0 + x, 15 + y, 0, 65, 78);
            gfx.PutPixel(1 + x, 15 + y, 1, 17, 29);
            gfx.PutPixel(2 + x, 15 + y, 4, 39, 62);
            gfx.PutPixel(3 + x, 15 + y, 5, 58, 91);
            gfx.PutPixel(4 + x, 15 + y, 7, 76, 117);
            gfx.PutPixel(5 + x, 15 + y, 8, 92, 141);
            gfx.PutPixel(6 + x, 15 + y, 11, 111, 163);
            gfx.PutPixel(7 + x, 15 + y, 13, 124, 181);
            gfx.PutPixel(8 + x, 15 + y, 15, 140, 197);
            gfx.PutPixel(9 + x, 15 + y, 16, 148, 207);
            gfx.PutPixel(10 + x, 15 + y, 18, 157, 216);
            gfx.PutPixel(11 + x, 15 + y, 18, 162, 220);
            gfx.PutPixel(12 + x, 15 + y, 18, 161, 221);
            gfx.PutPixel(13 + x, 15 + y, 18, 159, 218);
            gfx.PutPixel(14 + x, 15 + y, 17, 151, 211);
            gfx.PutPixel(15 + x, 15 + y, 16, 143, 202);
            gfx.PutPixel(16 + x, 15 + y, 15, 130, 188);
            gfx.PutPixel(17 + x, 15 + y, 13, 116, 171);
            gfx.PutPixel(18 + x, 15 + y, 11, 101, 152);
            gfx.PutPixel(19 + x, 15 + y, 10, 85, 127);
            gfx.PutPixel(20 + x, 15 + y, 6, 63, 100);
            gfx.PutPixel(21 + x, 15 + y, 5, 46, 72);
            gfx.PutPixel(22 + x, 15 + y, 3, 26, 39);
            gfx.PutPixel(23 + x, 15 + y, 1, 67, 84);
            gfx.PutPixel(1 + x, 16 + y, 0, 24, 38);
            gfx.PutPixel(2 + x, 16 + y, 3, 32, 49);
            gfx.PutPixel(3 + x, 16 + y, 3, 49, 78);
            gfx.PutPixel(4 + x, 16 + y, 6, 68, 106);
            gfx.PutPixel(5 + x, 16 + y, 7, 84, 129);
            gfx.PutPixel(6 + x, 16 + y, 9, 99, 150);
            gfx.PutPixel(7 + x, 16 + y, 11, 113, 167);
            gfx.PutPixel(8 + x, 16 + y, 12, 125, 181);
            gfx.PutPixel(9 + x, 16 + y, 13, 133, 192);
            gfx.PutPixel(10 + x, 16 + y, 16, 143, 201);
            gfx.PutPixel(11 + x, 16 + y, 16, 146, 205);
            gfx.PutPixel(12 + x, 16 + y, 16, 147, 206);
            gfx.PutPixel(13 + x, 16 + y, 15, 144, 204);
            gfx.PutPixel(14 + x, 16 + y, 16, 140, 199);
            gfx.PutPixel(15 + x, 16 + y, 15, 130, 188);
            gfx.PutPixel(16 + x, 16 + y, 13, 120, 176);
            gfx.PutPixel(17 + x, 16 + y, 13, 108, 159);
            gfx.PutPixel(18 + x, 16 + y, 9, 90, 138);
            gfx.PutPixel(19 + x, 16 + y, 8, 76, 115);
            gfx.PutPixel(20 + x, 16 + y, 7, 58, 90);
            gfx.PutPixel(21 + x, 16 + y, 4, 37, 59);
            gfx.PutPixel(22 + x, 16 + y, 3, 21, 30);
            gfx.PutPixel(23 + x, 16 + y, 0, 83, 103);
            gfx.PutPixel(1 + x, 17 + y, 0, 62, 78);
            gfx.PutPixel(2 + x, 17 + y, 2, 21, 33);
            gfx.PutPixel(3 + x, 17 + y, 3, 40, 64);
            gfx.PutPixel(4 + x, 17 + y, 4, 56, 89);
            gfx.PutPixel(5 + x, 17 + y, 6, 73, 113);
            gfx.PutPixel(6 + x, 17 + y, 8, 87, 133);
            gfx.PutPixel(7 + x, 17 + y, 9, 100, 150);
            gfx.PutPixel(8 + x, 17 + y, 10, 111, 165);
            gfx.PutPixel(9 + x, 17 + y, 12, 120, 176);
            gfx.PutPixel(10 + x, 17 + y, 12, 127, 184);
            gfx.PutPixel(11 + x, 17 + y, 13, 130, 188);
            gfx.PutPixel(12 + x, 17 + y, 14, 132, 190);
            gfx.PutPixel(13 + x, 17 + y, 14, 129, 187);
            gfx.PutPixel(14 + x, 17 + y, 14, 125, 182);
            gfx.PutPixel(15 + x, 17 + y, 13, 116, 171);
            gfx.PutPixel(16 + x, 17 + y, 12, 108, 159);
            gfx.PutPixel(17 + x, 17 + y, 11, 96, 142);
            gfx.PutPixel(18 + x, 17 + y, 9, 81, 123);
            gfx.PutPixel(19 + x, 17 + y, 7, 65, 99);
            gfx.PutPixel(20 + x, 17 + y, 6, 48, 74);
            gfx.PutPixel(21 + x, 17 + y, 2, 27, 45);
            gfx.PutPixel(22 + x, 17 + y, 2, 58, 74);
            gfx.PutPixel(2 + x, 18 + y, 0, 49, 64);
            gfx.PutPixel(3 + x, 18 + y, 2, 27, 45);
            gfx.PutPixel(4 + x, 18 + y, 4, 46, 72);
            gfx.PutPixel(5 + x, 18 + y, 5, 60, 94);
            gfx.PutPixel(6 + x, 18 + y, 7, 75, 114);
            gfx.PutPixel(7 + x, 18 + y, 7, 85, 132);
            gfx.PutPixel(8 + x, 18 + y, 8, 95, 144);
            gfx.PutPixel(9 + x, 18 + y, 9, 105, 156);
            gfx.PutPixel(10 + x, 18 + y, 10, 110, 164);
            gfx.PutPixel(11 + x, 18 + y, 11, 114, 169);
            gfx.PutPixel(12 + x, 18 + y, 12, 115, 169);
            gfx.PutPixel(13 + x, 18 + y, 11, 114, 168);
            gfx.PutPixel(14 + x, 18 + y, 13, 111, 162);
            gfx.PutPixel(15 + x, 18 + y, 10, 101, 153);
            gfx.PutPixel(16 + x, 18 + y, 10, 93, 140);
            gfx.PutPixel(17 + x, 18 + y, 8, 81, 124);
            gfx.PutPixel(18 + x, 18 + y, 7, 66, 105);
            gfx.PutPixel(19 + x, 18 + y, 5, 51, 81);
            gfx.PutPixel(20 + x, 18 + y, 3, 34, 55);
            gfx.PutPixel(21 + x, 18 + y, 2, 34, 49);
            gfx.PutPixel(22 + x, 18 + y, 0, 95, 116);
            gfx.PutPixel(2 + x, 19 + y, 0, 60, 84);
            gfx.PutPixel(3 + x, 19 + y, 1, 29, 42);
            gfx.PutPixel(4 + x, 19 + y, 2, 30, 50);
            gfx.PutPixel(5 + x, 19 + y, 3, 46, 73);
            gfx.PutPixel(6 + x, 19 + y, 5, 60, 93);
            gfx.PutPixel(7 + x, 19 + y, 6, 71, 110);
            gfx.PutPixel(8 + x, 19 + y, 7, 81, 124);
            gfx.PutPixel(9 + x, 19 + y, 8, 89, 135);
            gfx.PutPixel(10 + x, 19 + y, 8, 92, 141);
            gfx.PutPixel(11 + x, 19 + y, 9, 98, 146);
            gfx.PutPixel(12 + x, 19 + y, 10, 98, 148);
            gfx.PutPixel(13 + x, 19 + y, 10, 96, 145);
            gfx.PutPixel(14 + x, 19 + y, 10, 92, 139);
            gfx.PutPixel(15 + x, 19 + y, 9, 86, 131);
            gfx.PutPixel(16 + x, 19 + y, 8, 75, 117);
            gfx.PutPixel(17 + x, 19 + y, 7, 67, 103);
            gfx.PutPixel(18 + x, 19 + y, 5, 51, 83);
            gfx.PutPixel(19 + x, 19 + y, 4, 37, 59);
            gfx.PutPixel(20 + x, 19 + y, 3, 24, 36);
            gfx.PutPixel(21 + x, 19 + y, 4, 81, 102);
            gfx.PutPixel(3 + x, 20 + y, 0, 65, 81);
            gfx.PutPixel(4 + x, 20 + y, 1, 29, 42);
            gfx.PutPixel(5 + x, 20 + y, 2, 30, 50);
            gfx.PutPixel(6 + x, 20 + y, 4, 44, 69);
            gfx.PutPixel(7 + x, 20 + y, 4, 54, 86);
            gfx.PutPixel(8 + x, 20 + y, 5, 64, 100);
            gfx.PutPixel(9 + x, 20 + y, 6, 71, 110);
            gfx.PutPixel(10 + x, 20 + y, 6, 77, 118);
            gfx.PutPixel(11 + x, 20 + y, 8, 80, 122);
            gfx.PutPixel(12 + x, 20 + y, 7, 80, 123);
            gfx.PutPixel(13 + x, 20 + y, 7, 78, 121);
            gfx.PutPixel(14 + x, 20 + y, 7, 74, 114);
            gfx.PutPixel(15 + x, 20 + y, 8, 69, 106);
            gfx.PutPixel(16 + x, 20 + y, 6, 61, 93);
            gfx.PutPixel(17 + x, 20 + y, 6, 51, 78);
            gfx.PutPixel(18 + x, 20 + y, 3, 36, 59);
            gfx.PutPixel(19 + x, 20 + y, 3, 26, 39);
            gfx.PutPixel(20 + x, 20 + y, 4, 69, 86);
            gfx.PutPixel(4 + x, 21 + y, 0, 66, 84);
            gfx.PutPixel(5 + x, 21 + y, 0, 51, 66);
            gfx.PutPixel(6 + x, 21 + y, 1, 26, 43);
            gfx.PutPixel(7 + x, 21 + y, 3, 38, 60);
            gfx.PutPixel(8 + x, 21 + y, 3, 46, 73);
            gfx.PutPixel(9 + x, 21 + y, 4, 53, 83);
            gfx.PutPixel(10 + x, 21 + y, 4, 57, 90);
            gfx.PutPixel(11 + x, 21 + y, 5, 60, 94);
            gfx.PutPixel(12 + x, 21 + y, 5, 60, 95);
            gfx.PutPixel(13 + x, 21 + y, 6, 61, 93);
            gfx.PutPixel(14 + x, 21 + y, 5, 55, 87);
            gfx.PutPixel(15 + x, 21 + y, 5, 50, 79);
            gfx.PutPixel(16 + x, 21 + y, 4, 42, 66);
            gfx.PutPixel(17 + x, 21 + y, 4, 33, 50);
            gfx.PutPixel(18 + x, 21 + y, 3, 43, 60);
            gfx.PutPixel(19 + x, 21 + y, 5, 86, 107);
            gfx.PutPixel(6 + x, 22 + y, 0, 67, 84);
            gfx.PutPixel(7 + x, 22 + y, 1, 29, 44);
            gfx.PutPixel(8 + x, 22 + y, 1, 26, 44);
            gfx.PutPixel(9 + x, 22 + y, 2, 33, 54);
            gfx.PutPixel(10 + x, 22 + y, 3, 38, 61);
            gfx.PutPixel(11 + x, 22 + y, 3, 41, 65);
            gfx.PutPixel(12 + x, 22 + y, 3, 41, 66);
            gfx.PutPixel(13 + x, 22 + y, 4, 40, 62);
            gfx.PutPixel(14 + x, 22 + y, 4, 37, 58);
            gfx.PutPixel(15 + x, 22 + y, 4, 31, 49);
            gfx.PutPixel(16 + x, 22 + y, 2, 26, 39);
            gfx.PutPixel(17 + x, 22 + y, 2, 67, 84);
            gfx.PutPixel(18 + x, 22 + y, 0, 92, 115);
            gfx.PutPixel(7 + x, 23 + y, 0, 51, 102);
            gfx.PutPixel(8 + x, 23 + y, 0, 73, 90);
            gfx.PutPixel(9 + x, 23 + y, 0, 67, 86);
            gfx.PutPixel(10 + x, 23 + y, 0, 57, 77);
            gfx.PutPixel(11 + x, 23 + y, 0, 41, 61);
            gfx.PutPixel(12 + x, 23 + y, 2, 40, 55);
            gfx.PutPixel(13 + x, 23 + y, 1, 57, 77);
            gfx.PutPixel(14 + x, 23 + y, 1, 68, 89);
            gfx.PutPixel(15 + x, 23 + y, 0, 76, 98);
            gfx.PutPixel(16 + x, 23 + y, 0, 92, 104);

        
    }
}
