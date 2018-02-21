/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd),
    rng(std::random_device()()),
    wallHit({ L"wall_hit.wav" }),
    brickHit({ L"brick_hit1.wav" }),
    gameStart(L"game_start.wav"),
    gameOver(L"game_over.wav"),
    mainTheme(L"main_theme.wav", 0.0f, 119.0f),
    paddleHit({ L"paddle_hit.wav" }),
    paddle1(startPosPlayer1, 1),
    paddle2(startPosPlayer2, 2),
    lvlCtrl()

{
    balls[0].Init(Vec2(50.0f, 300.0f), Vec2(1.0f, -0.3f), 'r');
    balls[1].Init(Vec2(700.0f, 240.0f), Vec2(-1.0f, 0.3f), 'b');
    Vec2 test(5.0f, 0.0f);
    Vec2 test2 = test.RotateDeg(90.0f);

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}



void Game::UpdateModel()
{
    float dt = ft.Mark();

    if (!mainMusicPlaying) {
        //mainTheme.Play();
        mainMusicPlaying = true;
    }
    
    if (lvlCtrl.IsBetweenLevels())
    {
        lvlCtrl.Update(wnd.kbd);
        //reset paddle and ball position
        paddle1.Reset();
        paddle2.Reset();
        for (int i = 0; i < (sizeof(balls) / sizeof(*balls)); i++)
        {
            if (i == 0 || i == 1) {
                balls[i].Reset();
            }
            else 
            {
                balls[i].Kill();
            }
        }

    }
    else if (lostLevel)
    {
        if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
            lostLevel = false;
        }
    }

    else 
    {
        //move the ball and paddles
        for (Ball& b : balls) 
        {
            b.Update(dt);

            if (lvlCtrl.CheckCollisionAndBounce(b)) {
                brickHit.Play(rng);
            }

            // check for collision between ball and paddle and bounces the ball.
            paddle1.IsCollidingWith(b);
            paddle2.IsCollidingWith(b);

        }
        paddle1.Update(wnd.kbd, dt);
        paddle2.Update(wnd.kbd, dt);

        lvlCtrl.Update(wnd.kbd);
        

        if (!balls[0].IsAlive()) //Respawn main balls
        {
            ball1RespawnTimer += dt;
        }
        if (!balls[1].IsAlive())
        {
            ball2RespawnTimer += dt;
        }

        if (ball1RespawnTimer > ballRespawnTime) 
        {
            balls[0].Reset();
            ball1RespawnTimer = 0.0f;
        }
        if (ball2RespawnTimer > ballRespawnTime)
        {
            balls[1].Reset();
            ball2RespawnTimer = 0.0f; 
        }

        lostLevel = true;
        //check for level loss
        for (Ball& b : balls)
        {
            if (b.IsAlive())
            {
                lostLevel = false;
            }
        }


        if (wnd.kbd.KeyIsPressed(VK_SPACE))
        {
            //reset paddle and ball position
            paddle1.Reset();
            paddle2.Reset();
            for (int i = 0; i < (sizeof(balls) / sizeof(*balls)); i++)
            {
                if (i == 0 || i == 1) {
                    balls[i].Reset();
                }
                else
                {
                    balls[i].Kill();
                }
            }
            lvlCtrl.ReviveBricks();
        }
    }
    
}

void Game::ComposeFrame()
{
    if (lvlCtrl.IsBetweenLevels() )
    {
        lvlCtrl.Draw(gfx);
    }
    else if (lostLevel)
    {
        
    }
    else
    {
        paddle1.Draw(gfx);
        paddle2.Draw(gfx);
        lvlCtrl.Draw(gfx);


        for (Ball& b : balls)
        {
            if (b.IsAlive()) {
                b.Draw(gfx);
            }
        }
        
    }
   


    
        
}
