#pragma once
#include "Settings.h"

#include "RenderManager.h"
#include "Vector2.h"



class Apple final
{
	Vector2 _position{ APPLE_START_POSITION };
public:
	void Render(RenderManager& renderManager);
	Vector2 get_position()const noexcept;
	void set_position(Vector2 position) noexcept;
	[[nodiscard]]bool collision(Vector2 position) noexcept;
};
Vector2 get_random_grid() noexcept;