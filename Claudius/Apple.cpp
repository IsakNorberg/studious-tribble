#include "Apple.h"

void Apple::Render(RenderManager& renderManager)
{
	renderManager.draw(_position);
}

Vector2 Apple::get_position() const noexcept
{
	return _position;
}

void Apple::set_position(Vector2 position) noexcept
{
	_position = position;
}

[[nodiscard]] bool Apple::collision(Vector2 position) noexcept
{
	if (position ==_position) [[unlikely]]
	{
		set_position(get_random_grid());
		return true;
	}
	return false;
}

Vector2 get_random_grid() noexcept
{
	return { (rand() % GRID_AMUNT_X) * GRID_SIZE, (rand() % GRID_AMUNT_Y) * GRID_SIZE };
}
