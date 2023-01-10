#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>


void Player::Render(RenderManager& renderManager)
{
	renderManager.add_to_render_buffer(_position, _color);

	for (int i = 0; i < player_score; i++)
	{
		renderManager.add_to_render_buffer(parts[i]._position);
	}
}

void Player::Update()
{
	x_array_difference[0] = get_position().x - parts[0].get_position().x;
	y_array_difference[0] = get_position().y - parts[0].get_position().y;

	for (int i = 1; i < (player_size - 1); i++)
	{
			x_array_difference[i] = parts[i].get_position().x - parts[i + 1].get_position().x;
			y_array_difference[i] = parts[i].get_position().y - parts[i + 1].get_position().y;
	}

	if (moving_left == true)
	{
		change_position(-MOVEMENT_SPEED, 0);
		parts[0].change_position(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].change_position(x_array_difference[i - 1], y_array_difference[i - 1]);
		}
	}
	else if (moving_right == true)
	{
		change_position(MOVEMENT_SPEED, 0);
		parts[0].change_position(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].change_position(x_array_difference[i - 1], y_array_difference[i - 1]);
		}
	}
	else if (moving_up == true)
	{
		change_position(0, -MOVEMENT_SPEED);
		parts[0].change_position(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].change_position(x_array_difference[i - 1], y_array_difference[i - 1]);
		}
	}
	else if (moving_down == true)
	{
		change_position(0, MOVEMENT_SPEED);
		parts[0].change_position(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].change_position(x_array_difference[i - 1], y_array_difference[i - 1]);
		}
	}
}

void Player::OnKeyDown(KeyCode key)
{
	if (key == KeyCode::LEFT_ARROW)
	{
		moving_left = true;
		moving_right = false;
		moving_up = false;
		moving_down = false;
	}
	else if (key == KeyCode::RIGHT_ARROW)
	{
		moving_left = false;
		moving_right = true;
		moving_up = false;
		moving_down = false;
	}
	else if (key == KeyCode::UP_ARROW)
	{
		moving_left = false;
		moving_right = false;
		moving_up = true;
		moving_down = false;
	}
	else if (key == KeyCode::DOWN_ARROW)
	{
		moving_left = false;
		moving_right = false;
		moving_up = false;
		moving_down = true;
	}
}

void Player::ResetPlayer()
{
	player_score = 0;
	moving_right = false;
	moving_left = false;
	moving_up = false;
	moving_down = false;

	set_position(STARTING_POSITION);
}

Vector2 Player::get_position()
{
	return _position;
}

void Player::set_position(Vector2 position)
{
	_position = position;
}

void Player::change_position(int x, int y)
{
	Vector2 OutVector = { x,y };
	OutVector = OutVector + get_position();
	set_position(OutVector);
}

Vector2 Player::PlayerPart::get_position()
{
	return _position;
}

void Player::PlayerPart::set_position(Vector2 position)
{
	_position = position;
}

void Player::PlayerPart::change_position(int x, int y)
{
	Vector2 OutVector = { x,y };
	OutVector = OutVector + get_position();
	set_position(OutVector);
}
