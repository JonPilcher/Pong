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
			player1Wins = true;
			playsound = true;
		}
	}
	if (ball.IsGoalP2())
	{
		heightP2 = heightP2 + SBInc;
		if (heightP2 >= Graphics::ScreenHeight - 20)
		{
			gameOver = true;
			player2Wins = true;
			playsound = true;
		}
	}
}

bool ScoreBoard::GameOver()
{
	return gameOver;
}

bool ScoreBoard::Player1Wins()
{
	return player1Wins;
}

bool ScoreBoard::Player2Wins()
{
	return player2Wins;
}

