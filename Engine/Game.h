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
    void DrawPlayer1(int x, int y);
    void DrawPlayer2(int x, int y);
    void DrawBall(int x, int y);
    void DrawBall2(int x, int y);
    void DrawBrickRed(int x, int y);
    void DrawBrickBlue(int x, int y);
    void DrawBrickGrey(int x, int y);
    void DrawStartScreen(int x, int y);
    void DrawWinScreen(int x, int y);
    void Ball_collision_check();
    void Player_collision_check();
    void BuildLevel1();
    void BuildLevel2();
    void Brick_collision_check();
        
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

    

    std::random_device rd;
    std::mt19937 rng;

    int fps = 60;

    int x_player1 = 10;
    int y_player1 = 200;
    int x_player2 = 758;
    int y_player2 = 200;
    int width_player = 24;
    int height_player = 160;
    int y_ball2 = 200;
    int x_ball2 = 600;
    int xvel_ball2 = 3 * (120 / fps);
    int yvel_ball2 = 3 * (120 / fps);


    int y_ball    = 200;
    int x_ball    = 50;
    int xvel_ball = -3 * (120 / fps);
    int yvel_ball = 3 * (120 / fps);
    int width_ball = 24;
    int height_ball = 24;
    bool alive_ball = true;
    bool alive_ball2 = true;
    bool level1_built = false;
    bool level2_built = false;
    bool level1_clear = false;
    bool level2_clear = false;
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

    Brick bricks[12][9];

    SoundEffect wallHit;
    SoundEffect brickHit;
    Sound gameStart;
    Sound gameOver;
    Sound mainTheme;
    SoundEffect paddleHit;
    FrameTimer ft;


    
    /********************************/
};

