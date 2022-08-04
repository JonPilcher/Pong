#pragma once
#include "Graphics.h"

class Border
{
public:
	void Draw(Graphics& gfx);
	void DrawBottom(Graphics& gfx);
	void DrawLeft(Graphics& gfx);
	void DrawRight(Graphics& gfx);
private:
	int topX = 10;
	int topY = 10;
	int bottomX = 10;
	int bottomY = Graphics::ScreenHeight - 20;
	int leftX = 10;
	int leftY = 10;
	int rightX = Graphics::ScreenWidth - 20;
	int rightY = 10;
	int thickness = 10;
	static constexpr Color border = Colors::LightGray;
};