#pragma once		

#include "RenderManager.h"
#include "Vector2.h"
#include <ranges>

constexpr float MOVEMENT_SPEED = 10.0f;
constexpr Vector2 STARTING_POSITION = {300, 300};
constexpr SDL_Color RED = { 255,0,0,0 };

constexpr Vector2 UP = {0,-MOVEMENT_SPEED};
constexpr Vector2 DOWN = { 0,MOVEMENT_SPEED };
constexpr Vector2 RIGHT = { MOVEMENT_SPEED, 0 };
constexpr Vector2 LEFT = { -MOVEMENT_SPEED, 0 };

class PlayerPart final
{
	Vector2 _position{ STARTING_POSITION };
public:
	Vector2 get_position()const noexcept;
	void set_position(Vector2 position)noexcept;
	void move_in_direction(Vector2 direction)noexcept;

};

class Player final
{
	void move(Vector2 direction);
	void collides_with_self() noexcept;
	std::vector<PlayerPart> parts{ PlayerPart() };
	SDL_Keycode _lastInput{};
public:
	void set_last_input(SDL_Keycode key);
	void render(RenderManager& renderManager);				
	void update()noexcept;
	void reset() noexcept;
	void add_part() noexcept;

	Vector2 get_head_position()const noexcept;
	void set_head_position(Vector2 position)noexcept;
};