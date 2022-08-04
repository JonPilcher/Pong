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
	rng(rd())
{
	//std::uniform_int_distribution<int>vDist(-1, 1);
	//ball.Init(395, 295, vDist(rng), vDist(rng));
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
	if (!SB.GameOver())
	{
		paddle.UpdateP1(wnd.kbd);
		paddle.UpdateP2(wnd.kbd);
		ball.Update(paddle);
		ball.Goal();
		SB.Update(ball);
	}
}

void Game::ComposeFrame()
{
	border.Draw(gfx);
	paddle.DrawPlayer1(gfx);
	paddle.DrawPlayer2(gfx);
	ball.Draw(gfx);
	SB.DrawP1(gfx);
	SB.DrawP2(gfx);
}
