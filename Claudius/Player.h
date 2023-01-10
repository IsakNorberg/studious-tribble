#pragma once		

#include "RenderManager.h"
#include "KeyCode.h"
#include "Vector2.h"

constexpr float MOVEMENT_SPEED = 10.0f;
constexpr Vector2 STARTING_POSITION = {300, 300};
constexpr SDL_Color RED = { 255,0,0,0 };

struct Player
{
	struct PlayerPart
	{
		Vector2 get_position();
		void set_position(Vector2 position);
		void change_position(int x, int y); // remove
		Vector2 _position{STARTING_POSITION};
	};

	
	static const int player_size = 50;
	PlayerPart parts[player_size];  // vector
	
	Vector2 _position{ STARTING_POSITION };
	SDL_Color _color{RED};
	void OnKeyDown(KeyCode key);
	void Render(RenderManager& renderManager);				
	void Update();
	void ResetPlayer();

	Vector2 get_position();
	void set_position(Vector2 position);
	void change_position(int x, int y); //remove

	bool moving_right{ false };
	bool moving_left{ false };
	bool moving_up {false};
	bool moving_down{ false };
	bool new_snake {false};

	float x_array_difference[player_size] = {};
	float y_array_difference[player_size] = {};

	int player_score{ 0 };
};