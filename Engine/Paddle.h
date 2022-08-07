#pragma once
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	void DrawPlayer1(Graphics& gfx);
	void DrawPlayer2(Graphics& gfx);
	void UpdateP1(Keyboard& kbd, float dt);
	void UpdateP2(Keyboard& kbd, float dt);
	float GetP1X()const;
	float GetP1Y()const;
	float GetP2X()const;
	float GetP2Y()const;
	float GetWidth()const;
	float GetHeight()const;
private:
	float x1 = 30.0f;
	float y1 = 280.0f;
	float x2 = 760.0f;
	float y2 = 280.0f;
	float width = 10.0f;
	float height = 40.0f;
	float speed = 4.0f * 60.0f;
	float offset = 20.0f;
	static constexpr Color player1 = Colors::Blue;
	static constexpr Color player2 = Colors::Green;
};