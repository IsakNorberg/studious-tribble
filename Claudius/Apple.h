#pragma once

#include "RenderManager.h"
#include "Vector2.h"

constexpr Vector2 START_POSITION = { 100,200 };

class Apple final
{
	Vector2 _position{ START_POSITION };

public:
	void Render(RenderManager& renderManager);
	Vector2 get_position()const noexcept;
	void set_position(Vector2 position) noexcept;
	bool new_apple{ false };
};