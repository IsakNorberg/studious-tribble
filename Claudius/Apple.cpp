#pragma once

#include <iostream>
#include "Apple.h"
#include "RenderManager.h"


Apple::Apple(unsigned int width, unsigned int height)
{
	color = { 0, 255, 0, 0 };
	rect = { 100, 200, static_cast<int>(width), static_cast<int>(height) };
}


void Apple::Render(RenderManager& renderManager)
{
	renderManager.add_to_render_buffer(rect, color);
}

Vector2 Apple::get_position()
{
	return { rect.x, rect.y };
}

void Apple::set_position(Vector2 position)
{
	rect.x = position.x;
	rect.y = position.y;
}


