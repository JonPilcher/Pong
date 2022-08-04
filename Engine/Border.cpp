#include "Border.h"

void Border::Draw(Graphics& gfx)
{
	int width = rightX - topX + 10;
	int height = bottomY - topX;
	gfx.DrawRectDim(topX, topY, width, thickness, border);
	gfx.DrawRectDim(bottomX, bottomY, width, thickness, border);
	gfx.DrawRectDim(leftX, leftY, thickness, height, border);
	gfx.DrawRectDim(rightX, rightY, thickness, height, border);
}
