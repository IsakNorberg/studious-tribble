#pragma once

#include <iostream>
#include "Apple.h"
#include "RenderManager.h"

void Apple::Render(RenderManager& renderManager)
{
	renderManager.add_to_render_buffer(_position);
}

Vector2 Apple::get_position()
{
	return _position;
}

void Apple::set_position(Vector2 position)
{
	_position = position;
}


