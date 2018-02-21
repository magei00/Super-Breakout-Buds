/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Sound.h"
#include "SoundEffect.h"
#include <random>
#include "FrameTimer.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "Vec2.h"
#include "Rekt.h"
#include "LevelController.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
   
    
        
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

    
    
    std::mt19937 rng;


    Vec2 startPosPlayer1 = Vec2(10,200);
    Vec2 startPosPlayer2 = Vec2(758, 200);
   
    Ball balls[20];
    Paddle paddle1;
    Paddle paddle2;
    LevelController lvlCtrl;

    
    bool level1_built = false;
    bool level2_built = false;
    bool level1_clear = false;
    bool level2_clear = false;
    bool lostLevel = false;
    bool even = true;
    bool game_start = false;
    bool win_screen = false;
    bool level2_screen = false;
    bool running = false;
    bool useonce = true;
    bool mainMusicPlaying = false;
    bool gameOverOnce = true;
    bool doOnce1 = true;
    bool doOnce2 = true;

    float ballRespawnTime = 10.0f;
    float ball1RespawnTimer = 0.0f;
    float ball2RespawnTimer = 0.0f;

    //Brick bricks[12][9];

    SoundEffect wallHit;
    SoundEffect brickHit;
    Sound gameStart;
    Sound gameOver;
    Sound mainTheme;
    SoundEffect paddleHit;
    FrameTimer ft;
    


    
    /********************************/
};

