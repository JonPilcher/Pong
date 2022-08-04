#include "Paddle.h"

void Paddle::DrawPlayer1(Graphics& gfx)
{
	gfx.DrawRectDim(x1, y1, width, height, player1);
}

void Paddle::DrawPlayer2(Graphics& gfx)
{
	gfx.DrawRectDim(x2, y2, width, height, player2);
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
	if (y1 >= (Graphics::ScreenHeight- offset)-height)
	{
		y1 = (Graphics::ScreenHeight - offset) - height;
	}
}

void Paddle::UpdateP2(Keyboard& kbd)
{
	int offset = 20;
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
	if (y2 >= (Graphics::ScreenHeight - offset) - height)
	{
		y2 = (Graphics::ScreenHeight - offset) - height;
	}
}

int Paddle::GetP1X()const
{
	return x1;
}

int Paddle::GetP1Y()const
{
	return y1;
}

int Paddle::GetP2X()const
{
	return x2;
}

int Paddle::GetP2Y()const
{
	return y2;
}

int Paddle::GetWidth()const
{
	return width;
}

int Paddle::GetHeight()const
{
	return height;
}
