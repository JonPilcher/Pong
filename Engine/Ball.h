#pragma once
#include "Graphics.h"
#include "Paddle.h"
#include "SpriteCodex.h"

class Ball
{
public:
	void Draw(Graphics& gfx);
	void Goal();
	void Update(const Paddle& paddle );
	bool IsGoalP1();
	bool IsGoalP2();
	void Init(float in_x, float in_y, float in_vx, float in_vy);
	bool TestCollisionPaddle1(const Paddle& paddle)const;
	bool TestCollisionPaddle2(const Paddle& paddle)const;
private:
	Paddle paddle;
	float x = 395.0f;
	float y = 295.0f;
	float vx = -1.0f;
	float vy = -1.0f;
	float dim = 10.0f;
	float offset = 20.0f;
	static constexpr Color ball = Colors::Yellow;
	bool isGoalP1 = false;
	bool isGoalP2;
};
