#pragma once

#include "RenderManager.h"
#include "Vector2.h"

constexpr Vector2 START_POSITION = { 100,200 };
constexpr int GRID_AMUNT_Y = 70;
constexpr int GRID_AMUNT_X = 125;
constexpr int GRID_SIZE = 10;

class Apple final
{
	Vector2 _position{ START_POSITION };
public:
	void Render(RenderManager& renderManager);
	Vector2 get_position()const noexcept;
	void set_position(Vector2 position) noexcept;
	bool collision(Vector2 position) noexcept;
};
Vector2 get_random_grid() noexcept;