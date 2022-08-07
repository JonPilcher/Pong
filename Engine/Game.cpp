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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(rd()),
	vDist(-2.0f,2.0f)
{

	//std::uniform_int_distribution<int>kickOff(1, 2);
	//std::uniform_real_distribution<float>vDist(-2.0f, 2.0f);

	ball.Init(400, 300, -3.0f, vDist(rng));
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
	if (isStarted)
	{
		if (!SB.GameOver())
		{
			paddle.UpdateP1(wnd.kbd);
			paddle.UpdateP2(wnd.kbd);
			ball.Update(paddle,vDist(rng));
			ball.Goal();
			SB.Update(ball);
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
	{
		isStarted = true;
	}
}

void Game::ComposeFrame()
{
	if (!isStarted)
	{
		sprite.DrawTitlePong(190, 120, gfx);
		sprite.DrawPressEnter(190, 300, gfx);
	}
	else
	{
		border.Draw(gfx);
		paddle.DrawPlayer1(gfx);
		paddle.DrawPlayer2(gfx);
		SB.DrawP1(gfx);
		SB.DrawP2(gfx);

		if (!SB.GameOver())
		{
			ball.Draw(gfx);
		}
		if (SB.Player1Wins())
		{
			sprite.DrawPlayer1Wins(190, 210, gfx);
		}
		if (SB.Player2Wins())
		{
			sprite.DrawPlayer2Wins(190, 210, gfx);
		}
	}
}
