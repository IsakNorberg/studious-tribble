#pragma once

#include "KeyCode.h"
#include "RenderManager.h"
#include "Vector2.h"

constexpr Vector2 START_POSITION = { 100,200 };

class Apple final
{
	Vector2 _position{ START_POSITION };

public:
	void Render(RenderManager& renderManager);
	Vector2 get_position();
	void set_position(Vector2 position);
	bool new_apple{ false };
};