#include "Paddle.h"

void Paddle::DrawPlayer1(Graphics& gfx)
{
	gfx.DrawRectDim(int(x1),int( y1),int( width),int( height), player1);
}

void Paddle::DrawPlayer2(Graphics& gfx)
{
	gfx.DrawRectDim(int(x2), int(y2), int(width), int(height), player2);
}

void Paddle::UpdateP1(Keyboard& kbd)
{
	if (kbd.KeyIsPressed('W'))
	{
		y1 = y1 - speed;
	}
	if (kbd.KeyIsPressed('S'))
	{
		y1 = y1 + speed;
	}

	if (y1 <= offset)
	{
		y1 = offset;
	}
	if (y1 >= int(Graphics::ScreenHeight- offset)-height)
	{
		y1 = int(Graphics::ScreenHeight - offset) - height;
	}
}

void Paddle::UpdateP2(Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		y2 = y2 - speed;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y2 = y2 + speed;
	}

	if (y2 <= offset)
	{
		y2 = offset;
	}
	if (y2 >= int(Graphics::ScreenHeight - offset) - height)
	{
		y2 = int(Graphics::ScreenHeight - offset) - height;
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
