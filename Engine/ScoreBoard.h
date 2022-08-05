#pragma once
#include "Graphics.h"
#include "Ball.h"

class ScoreBoard
{
public:
	void DrawP1(Graphics& gfx);
	void DrawP2(Graphics& gfx);
	void Update(Ball& ball);
	bool GameOver();
	bool Player1Wins();
	bool Player2Wins();
private:
	int PX1 = 0;
	int PY1 = 10;
	int PX2 = Graphics::ScreenWidth - 10;
	int PY2 = 10;
	int width = 10;
	int heightP1 = 0;
	int heightP2 = 0;
	int SBInc = 20;
	static constexpr Color P1 = Colors::Blue;
	static constexpr Color P2 = Colors::Green;
	bool gameOver = false;
	bool player1Wins = false;
	bool player2Wins = false;
};