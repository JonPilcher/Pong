#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawGameOver(int x, int y, Graphics& gfx);
	static void DrawTitle(int x, int y, Graphics& gfx);
	static void DrawTitlePong(int x, int y, Graphics& gfx);
	static void DrawPressEnter(int x, int y, Graphics& gfx);
	static void DrawPlayer1Wins(int x, int y, Graphics& gfx);
	static void DrawPlayer2Wins(int x, int y, Graphics& gfx);
	static void DrawCircle(int x, int y, Graphics& gfx);
};