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
	void Init(int in_x, int in_y, int in_vx, int in_vy);
	bool TestCollisionPaddle1(const Paddle& paddle)const;
	bool TestCollisionPaddle2(const Paddle& paddle)const;
private:
	Paddle paddle;
	int x = 395;
	int y = 295;
	int vx = 3;
	int vy = -3;
	int dim = 10;
	int offset = 20;
	static constexpr Color ball = Colors::Yellow;
	bool isGoalP1 = false;
	bool isGoalP2;
};
