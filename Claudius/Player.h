#pragma once		
#include "Settings.h"

#include "RenderManager.h"
#include "Vector2.h"
#include <ranges>



using PlayerPart = Vector2;

class Player final
{
	void move(Vector2 direction) noexcept;
	std::vector<PlayerPart> parts{ PlayerPart({ STARTING_POSITION }) };
	
	Vector2 _direction{};
public:
	bool collides_with_self() const noexcept;
	void set_last_input(SDL_Keycode key) noexcept;
	void render(const RenderManager& r) const;				
	void update() noexcept;
	void reset() noexcept;
	void add_part() noexcept;

	Vector2 get_head_position()const noexcept;
	void set_head_position(Vector2 position)noexcept;
};