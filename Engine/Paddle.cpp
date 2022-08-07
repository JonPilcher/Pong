#include "Paddle.h"

void Paddle::DrawPlayer1(Graphics& gfx)
{
	gfx.DrawRectDim(int(x1),int( y1),int( width),int( height), player1);
}

void Paddle::DrawPlayer2(Graphics& gfx)
{
	gfx.DrawRectDim(int(x2), int(y2), int(width), int(height), player2);
}

void Paddle::UpdateP1(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed('W'))
	{
		y1 = y1 - speed * dt;
	}
	if (kbd.KeyIsPressed('S'))
	{
		y1 = y1 + speed * dt;
	}

	if (y1 <= offset)
	{
		y1 = offset * dt;
	}
	if (y1 >= int(Graphics::ScreenHeight- offset)-height)
	{
		y1 = int(Graphics::ScreenHeight - offset) - height * dt;
	}
}

void Paddle::UpdateP2(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		y2 = y2 - speed * dt;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y2 = y2 + speed * dt;
	}

	if (y2 <= offset)
	{
		y2 = offset * dt;
	}
	if (y2 >= int(Graphics::ScreenHeight - offset) - height)
	{
		y2 = int(Graphics::ScreenHeight - offset) - height * dt;
	}
}

float Paddle::GetP1X()const
{
	return x1;
}

float Paddle::GetP1Y()const
{
	return y1;
}

float Paddle::GetP2X()const
{
	return x2;
}

float Paddle::GetP2Y()const
{
	return y2;
}

float Paddle::GetWidth()const
{
	return width;
}

float Paddle::GetHeight()const
{
	return height;
}
