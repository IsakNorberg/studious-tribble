#pragma once

#include "KeyCode.h"
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"
#include "RenderManager.h"

class Apple
{
	SDL_Rect sdl_rect;

	Rectangle rect;
	Color color;

public:
	Apple(unsigned int width, unsigned int height);
	void Render(RenderManager& renderManager);
	Vector2 get_position();
	void set_position(Vector2 position);


	bool new_apple{ false };
};