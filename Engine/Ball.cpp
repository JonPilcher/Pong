#include "Ball.h"

void Ball::Draw(Graphics& gfx)
{
	gfx.DrawCircle(int(x),int( y),int( dim / 2), ball);
}

void Ball::Goal()
{
	if ((x - dim/2) < offset)
	{
		
		x = offset + dim/2;
		isGoalP2 = true;
		x = 400.0f;
		y = 300.0f;
		vx = +vx;
	}
	else
	{
		isGoalP2 = false;
	}
	if ((x- dim/2) > int(Graphics::ScreenWidth - offset))
	{
		x = int(Graphics::ScreenWidth - offset) - dim/2;
		isGoalP1 = true;
		x = 400.0f;
		y = 300.0f;
		vx = +vx;
	}
	else
	{
		isGoalP1 = false;
	}
}

void Ball::Update(const Paddle& paddle, float vDist_in)
{
	const float bottom = y + dim/2;

	
	x += vx;
	y += vy;
	
	if (TestCollisionPaddle1(paddle))
	{
		x = paddle.GetP1X() + paddle.GetWidth()+dim/2;
		vx = -vx;
		vy = vDist_in;
	}
	else if (TestCollisionPaddle2(paddle) )
	{
		x = paddle.GetP2X()-dim/2 ;
		vx = -vx;
		vy = vDist_in;
	}
	if (y < offset + dim/2)
	{
		y = offset + dim/2;
		vy = -vy;
	}
	else if (bottom > int(Graphics::ScreenHeight - offset))
	{
		y = (int(Graphics::ScreenHeight) - offset - dim/2);
		vy = -vy;
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

void Ball::Init(float in_x, float in_y, float in_vx, float in_vy)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
}

bool Ball::TestCollisionPaddle1(const Paddle& paddle) const
{
	const float paddle1Right = paddle.GetP1X() + paddle.GetWidth();
	const float paddle1Bottom = paddle.GetP1Y() + paddle.GetHeight();
	const float ballRight = x + dim/2;
	const float ballBottom = y + dim/2;

	return paddle1Right >= x - dim/2 &&
		paddle1Right <= ballRight &&
		paddle1Bottom >= y - dim/2 &&
		paddle.GetP1Y() <= ballBottom;
}

bool Ball::TestCollisionPaddle2(const Paddle& paddle) const
{
	const float paddle2Right = (paddle.GetP2X() ) + paddle.GetWidth();
	const float paddle2Bottom = (paddle.GetP2Y() ) + paddle.GetHeight();
	const float ballRight = x + dim/2;
	const float ballBottom = y + dim/2;

	return paddle.GetP2X() >= x - dim/2 &&
		paddle.GetP2X() <= ballRight &&
		paddle2Bottom >= y - dim/2 &&
		paddle.GetP2Y() <= ballBottom;
}
