#include "Ball.h"

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawCircle(x, y, gfx);
}

void Ball::Goal()
{
	if (x < offset)
	{
		x = offset;
		isGoalP2 = true;
		x = 395;
		y = 295;
		vx = +vx;
	}
	else
	{
		isGoalP2 = false;
	}
	if (x > (Graphics::ScreenWidth - offset) - dim)
	{
		x = (Graphics::ScreenWidth - offset) - dim;
		isGoalP1 = true;
		x = 395;
		y = 295;
		vx = +vx;
	}
	else
	{
		isGoalP1 = false;
	}
}

void Ball::Update(const Paddle& paddle)
{
	const int right = x + dim;
	const int bottom = y + dim;

	x += vx;
	y += vy;
	
	if (TestCollisionPaddle1(paddle))
	{
		x = paddle.GetP1X() + paddle.GetWidth();
		vx = -vx;
	}
	else if (TestCollisionPaddle2(paddle) )
	{
		x = paddle.GetP2X() - dim;
		vx = -vx;
	}
	if (y < offset)
	{
		y = offset;
		vy = -vy;
	}
	else if (bottom > Graphics::ScreenHeight - offset)
	{
		y = (Graphics::ScreenHeight - offset) - dim;
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

void Ball::Init(int in_x, int in_y, int in_vx, int in_vy)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
}

bool Ball::TestCollisionPaddle1(const Paddle& paddle) const
{
	const int paddle1Right = paddle.GetP1X() + paddle.GetWidth();
	const int paddle1Bottom = paddle.GetP1Y() + paddle.GetHeight();
	const int ballRight = x + dim;
	const int ballBottom = y + dim;

	return paddle1Right >= x &&
		paddle1Right <= ballRight &&
		paddle1Bottom >= y &&
		paddle.GetP1Y() <= ballBottom;
}

bool Ball::TestCollisionPaddle2(const Paddle& paddle) const
{
	const int paddle2Right = paddle.GetP2X() + paddle.GetWidth();
	const int paddle2Bottom = paddle.GetP2Y() + paddle.GetHeight();
	const int ballRight = x + dim;
	const int ballBottom = y + dim;

	return paddle.GetP2X() >= x &&
		paddle.GetP2X() <= ballRight &&
		paddle2Bottom >= y &&
		paddle.GetP2Y() <= ballBottom;
}
