#include "LevelController.h"



LevelController::LevelController()
{
    const float bWidth = Brick::GetWidth();
    const float bHeight = Brick::GetHeight();
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Vec2 pos(300+i*bWidth,0+j*bHeight);
            bricks[i][j].Init(pos,'g');
        }
    }
}

void LevelController::Update(Keyboard & kbd)
{
    if (inBetweenLevels)
    {
        if (kbd.KeyIsPressed(VK_SPACE))
        {
            inBetweenLevels = false;
            BuildLevel(currentLevel);
        }
    }
    else 
    {
        //check if level is done

        inBetweenLevels = true;
        currentLevel++;

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (bricks[i][j].IsAlive())
                {
                    inBetweenLevels = false;
                    currentLevel--;
                    
                }
            }
        }
//endloop:
    }
}

void LevelController::BuildLevel(int levelNumber)
{

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            bricks[i][j].Revive();
            bricks[i][j].SetType('g');
        }
    }

    if (levelNumber == 1)
    {
        BuildLevel1();
    }
    else if (levelNumber == 2)
    {
        
    }//extend with more elseifs to add more levels
}

void LevelController::BuildLevel1()
{
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i < 5) {
                if (j - i >= 0 && j + i <= 8) {
                    bricks[i][j].SetType('r');
                }
            }
            if (i >= 5) {
                if (j - i<0 && j + i >= 9) {
                    bricks[i][j].SetType('b');
                }
            }
        }

    }
}

bool LevelController::CheckCollisionAndBounce(Ball & ball)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Rekt brickBox = bricks[i][j].GetRekt();
            Rekt ballBox = ball.GetRekt();
            if (brickBox.IsOverlappingWith(ballBox) && bricks[i][j].IsAlive())
            {

                float overlapTop = ballBox.bottom - brickBox.top;
                float overlapLeft = ballBox.right - brickBox.left;
                float overlapRight = brickBox.right - ballBox.left;
                float overlapBottom = brickBox.bottom - ballBox.top;
                if ( overlapTop <= overlapLeft && overlapTop <= overlapRight)
                {
                    ball.BounceUp();

                }
                else if (overlapBottom <= overlapLeft && overlapBottom <= overlapRight)
                {
                    ball.BounceDown();
                }
                else if(overlapLeft < overlapTop && overlapLeft < overlapBottom)
                {
                    ball.BounceLeft();
                }
                else
                {
                    ball.BounceRight();
                }

                bricks[i][j].Destroy();
                return true;
            }
        }
    }
    return false;
}

void LevelController::Draw(Graphics & gfx)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (bricks[i][j].IsAlive())
            {
                bricks[i][j].Draw(gfx);
            }
            
        }
    }
}
