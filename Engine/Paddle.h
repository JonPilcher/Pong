#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	void DrawPlayer1(Graphics& gfx);
	void DrawPlayer2(Graphics& gfx);
	void UpdateP1(Keyboard& kbd);
	void UpdateP2(Keyboard& kbd);
	int GetP1X()const;
	int GetP1Y()const;
	int GetP2X()const;
	int GetP2Y()const;
	int GetWidth()const;
	int GetHeight()const;
private:
	int x1 = 30;
	int y1 = 280;
	int x2 = 760;
	int y2 = 280;
	int width = 10;
	int height = 40;
	int speed = 4;
	int offset = 20;
	static constexpr Color player1 = Colors::Blue;
	static constexpr Color player2 = Colors::Green;
};