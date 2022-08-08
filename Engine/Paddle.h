#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"

class Paddle
{
public:
	void DrawPlayer1(Graphics& gfx);
	void DrawPlayer2(Graphics& gfx);
	void UpdateP1(Keyboard& kbd, float dt);
	void UpdateP2(Keyboard& kbd, float dt);
	Vec2 GetPosP1()const;
	Vec2 GetPosP2()const;
	float GetWidth()const;
	float GetHeight()const;
private:
	Vec2 posP1 = Vec2(30.0f, 280.0f);
	Vec2 posP2 = Vec2(760.0f, 280.0f);
	float width = 10.0f;
	float height = 40.0f;
	float speed = 4.0f * 60.0f;
	float offset = 20.0f;
	static constexpr Color player1 = Colors::Blue;
	static constexpr Color player2 = Colors::Green;
};