#pragma once		

#include "RenderManager.h"
#include "KeyCode.h"
#include "Vector2.h"

constexpr float MOVEMENT_SPEED = 10.0f;
constexpr Vector2 STARTING_POSITION = {300, 300};
constexpr SDL_Color RED = { 255,0,0,0 };
constexpr Vector2 UP = {0,-MOVEMENT_SPEED};
constexpr Vector2 DOWN = { 0,MOVEMENT_SPEED };
constexpr Vector2 RIGHT = { MOVEMENT_SPEED, 0 };
constexpr Vector2 LEFT = { -MOVEMENT_SPEED, 0 };

class PlayerPart
{
	Vector2 _position{ STARTING_POSITION };
public:
	Vector2 get_position()const noexcept;
	void set_position(Vector2 position)noexcept;
	void change_position(Vector2 position)noexcept; // rename

};

class Player final
{
	static const int player_size = 50;
	void move(Vector2 direction);
	Vector2 _position{ STARTING_POSITION };
	SDL_Color _color{RED};
public:
	PlayerPart parts[player_size];  // vector;
	void Render(RenderManager& renderManager);				
	void move(SDL_Keycode input)noexcept;
	void reset_player() noexcept;

	Vector2 get_head_position()const noexcept;
	void set_head_position(Vector2 position)noexcept;
	//void change_position(Vector2 position)noexcept; //rename

	int x_array_difference[player_size] = {};
	int y_array_difference[player_size] = {};

	int player_score{ 1 };
};