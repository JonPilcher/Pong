#include "Paddle.h"

void Paddle::DrawPlayer1(Graphics& gfx)
{
	gfx.DrawRectDim(int(posP1.x),int(posP1.y),int( width),int( height), player1);
}

void Paddle::DrawPlayer2(Graphics& gfx)
{
	gfx.DrawRectDim(int(posP2.x), int(posP2.y), int(width), int(height), player2);
}

void Paddle::UpdateP1(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed('W'))
	{
		posP1.y -= speed * dt;
	}
	if (kbd.KeyIsPressed('S'))
	{
		posP1.y += speed * dt;
	}

	if (posP1.y <= offset)
	{
		posP1.y = offset;
	}
	if (posP1.y >= int(Graphics::ScreenHeight- offset)-height)
	{
		posP1.y = int(Graphics::ScreenHeight - offset) - height ;
	}
}

void Paddle::UpdateP2(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		posP2.y -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		posP2.y += speed * dt;
	}

	if (posP2.y <= offset)
	{
		posP2.y = offset ;
	}
	if (posP2.y >= int(Graphics::ScreenHeight - offset) - height)
	{
		posP2.y = int(Graphics::ScreenHeight - offset) - height ;
	}
}

Vec2 Paddle::GetPosP1() const
{
	return posP1;
}

Vec2 Paddle::GetPosP2() const
{
	return posP2;
}



float Paddle::GetWidth()const
{
	return width;
}

float Paddle::GetHeight()const
{
	return height;
}
