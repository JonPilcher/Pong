#include "Ball.h"

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawCircle(int(pos.x),int( pos.y),int( dim / 2), ball);
}

void Ball::Goal()
{
	if ((pos.x - dim/2) < offset)
	{
		
		pos.x = offset + dim/2;
		isGoalP2 = true;
		pos.x = 400.0f;
		pos.y = 300.0f;
		vel.x = +vel.x;
	}
	else
	{
		isGoalP2 = false;
	}
	if ((pos.x- dim/2) > int(Graphics::ScreenWidth - offset))
	{
		pos.x = int(Graphics::ScreenWidth - offset) - dim/2;
		isGoalP1 = true;
		pos.x = 400.0f;
		pos.y = 300.0f;
		vel.x = +vel.x;
	}
	else
	{
		isGoalP1 = false;
	}
}

void Ball::Update(const Paddle& paddle, float vDist_in, float dt)
{
	const float bottom = pos.y + dim/2;

	
	pos.x += vel.x * dt;
	pos.y += vel.y * dt;
	
	if (TestCollisionPaddle1(paddle))
	{
		pos.x = paddle.GetPosP1().x + paddle.GetWidth()+dim/2;
		vel.x = -vel.x;
		vel.y = vDist_in;
	}
	else if (TestCollisionPaddle2(paddle) )
	{
		pos.x = paddle.GetPosP2().x -dim/2 ;
		vel.x = -vel.x;
		vel.y = vDist_in;
	}
	if (pos.y < offset + dim/2)
	{
		pos.y = offset + dim/2;
		vel.y = -vel.y;
	}
	else if (bottom > int(Graphics::ScreenHeight - offset))
	{
		pos.y = (int(Graphics::ScreenHeight) - offset - dim/2);
		vel.y = -vel.y;
	}
}

bool Ball::IsGoalP1()
{
	return isGoalP1;
}

bool Ball::IsGoalP2()
{
	return isGoalP2;
}

void Ball::Init(const Vec2& pos_in, const Vec2 vel_in)
{
	pos = pos_in;
	vel = vel_in;
}

bool Ball::TestCollisionPaddle1(const Paddle& paddle) const
{
	const float paddle1Right = paddle.GetPosP1().x + paddle.GetWidth();
	const float paddle1Bottom = paddle.GetPosP1().y + paddle.GetHeight();
	const float ballRight = pos.x + dim/2;
	const float ballBottom = pos.y + dim/2;

	return paddle1Right >= pos.x - dim/2 &&
		paddle1Right <= ballRight &&
		paddle1Bottom >= pos.y - dim/2 &&
		paddle.GetPosP1().y <= ballBottom;
}

bool Ball::TestCollisionPaddle2(const Paddle& paddle) const
{
	const float paddle2Right = (paddle.GetPosP2().x ) + paddle.GetWidth();
	const float paddle2Bottom = (paddle.GetPosP2().y ) + paddle.GetHeight();
	const float ballRight = pos.x + dim/2;
	const float ballBottom = pos.y + dim/2;

	return paddle.GetPosP2().x >= pos.x - dim/2 &&
		paddle.GetPosP2().x <= ballRight &&
		paddle2Bottom >= pos.y - dim/2 &&
		paddle.GetPosP2().y <= ballBottom;
}
