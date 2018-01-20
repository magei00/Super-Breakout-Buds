#pragma once
#include "Brick.h"
#include "Keyboard.h"
#include "Ball.h"
#include "Graphics.h"

class LevelController
{
public:
    LevelController();
    void Update(Keyboard& kbd);
    void BuildLevel(int levelNumber);
    void BuildLevel1();
    void CheckCollisionAndBounce(Ball& ball);
    void Draw(Graphics& gfx);

private:
    int currentLevel = 0;
    bool inBetweenLevels = true;
    static constexpr int height = 9;
    static constexpr int width = 10;
    Brick bricks[width][height];
    //implement more levels here
};