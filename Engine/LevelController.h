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
    void BuildLevel2();
    bool CheckCollisionAndBounce(Ball& ball);
    void KillAllCheat(Keyboard& kbd);
    void Draw(Graphics& gfx);
    bool IsBetweenLevels();
    void DrawStartScreen(Graphics& gfx);
    void DrawWinScreen(Graphics& gfx);

private:
    int currentLevel = 1;
    static constexpr int lastLevel = 3;
    bool inBetweenLevels = true;
    static constexpr int height = 9;
    static constexpr int width = 10;
    Brick bricks[width][height];
    //implement more levels here
};