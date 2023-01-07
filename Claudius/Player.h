#pragma once		

#include "RenderManager.h"
#include "Transform.h"
#include "Color.h"
#include "Rectangle.h"
#include "KeyCode.h"



struct Player
{
	struct PlayerPart
	{
		SDL_Rect rect;
		SDL_Color color;
	};

	
	static const int player_size = 50;
	PlayerPart parts[player_size];
	
	SDL_Rect rect;
	SDL_Color color;
	void OnKeyDown(KeyCode key);
	void Initialize();
	void Render(RenderManager& renderManager);				
	void Update();
	void ResetPlayer();

	unsigned int size = 10;
	const float movement_speed = 10.0f;
	const float starting_x = 300.0f;
	const float starting_y = 300.0f;

	bool moving_right = false;
	bool moving_left = false;
	bool moving_up = false;
	bool moving_down = false;
	bool new_snake = false;

	float x_array_difference[player_size] = {};
	float y_array_difference[player_size] = {};

	int player_score = 0;
};