#pragma once
#include "Graphics.h"
#include "Paddle.h"
#include "SpriteCodex.h"
#include <random>
#include "Vec2.h"

class Ball
{
public:
	void Draw(Graphics& gfx);
	void Goal();
	void Update(const Paddle& paddle, float vDist_in,float dt);
	bool IsGoalP1();
	bool IsGoalP2();
	void Init(const Vec2& pos_in,const Vec2 vel_in);
	bool TestCollisionPaddle1(const Paddle& paddle)const;
	bool TestCollisionPaddle2(const Paddle& paddle)const;
private:

	std::random_device rd;
	std::mt19937 rng;
	Paddle paddle;
	Vec2 pos = Vec2 (395.0f, 295.0f); 
	Vec2 vel;
	float dim = 10.0f;
	float offset = 20.0f;
	static constexpr Color ball = Colors::Yellow;
	bool isGoalP1 = false;
	bool isGoalP2 = false;
};
