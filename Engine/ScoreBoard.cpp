#include "ScoreBoard.h"

void ScoreBoard::DrawP1(Graphics& gfx)
{
	gfx.DrawRectDim(PX1, PY1, width, heightP1, P1);
}

void ScoreBoard::DrawP2(Graphics& gfx)
{
	gfx.DrawRectDim(PX2, PY2, width, heightP2, P2);
}

void ScoreBoard::Update(Ball& ball)
{
	if (ball.IsGoalP1())
	{
		heightP1 = heightP1 + SBInc;
		if (heightP1 >= Graphics::ScreenHeight - 20)
		{
			gameOver = true;
		}
	}
	if (ball.IsGoalP2())
	{
		heightP2 = heightP2 + SBInc;
		if (heightP2 >= Graphics::ScreenHeight - 20)
		{
			gameOver = true;
		}
	}
}

bool ScoreBoard::GameOver()
{
	return gameOver;
}
