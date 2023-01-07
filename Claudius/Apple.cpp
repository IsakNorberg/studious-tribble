#pragma once

#include <iostream>
#include "Apple.h"
#include "RenderManager.h"


Apple::Apple(unsigned int width, unsigned int height)
{
	color = { 0, 255, 0, 0 };
	sdl_rect = { 100, 200, static_cast<int>(width), static_cast<int>(height) };
}


void Apple::Render(RenderManager& renderManager)
{
	//taca a color and a sdl rect
	renderManager.add_to_render_buffer(rect, color, trans);
}

Vector2 Apple::get_position()
{
	return { sdl_rect.x, sdl_rect.y };
}


