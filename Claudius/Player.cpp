#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>

void Player::Initialize()
{
	color = { 0,255,0,0 };
	rect = { starting_x, starting_y, static_cast<int>(size), static_cast<int>(size) };
	player_score = 0;

	for (int i = 0; i < player_size; i++)
	{
		parts[i].color = color;
		parts[i].rect = rect;
	}
}

void Player::Render(RenderManager& renderManager)
{
	renderManager.add_to_render_buffer(rect, color);

	for (int i = 0; i < player_score; i++)
	{
		renderManager.add_to_render_buffer(parts[i].rect, parts[i].color);
	}
}

void Player::Update()
{
	x_array_difference[0] = trans.GetX() - parts[0].trans.GetX();
	y_array_difference[0] = trans.GetY() - parts[0].trans.GetY();

	for (int i = 1; i < (player_size - 1); i++)
	{
			x_array_difference[i] = parts[i].trans.GetX() - parts[i + 1].trans.GetX();
			y_array_difference[i] = parts[i].trans.GetY() - parts[i + 1].trans.GetY();
	}

	if (moving_left == true)
	{
		trans.ChangePosition(-movement_speed, 0);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		}
	}
	else if (moving_right == true)
	{
		trans.ChangePosition(movement_speed, 0);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		}
	}
	else if (moving_up == true)
	{
		trans.ChangePosition(0, -movement_speed);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		}
	}
	else if (moving_down == true)
	{
		trans.ChangePosition(0, movement_speed);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
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

	set_position({ starting_x, starting_y });
}

Vector2 Player::get_position()
{
	return {rect.x, rect.y};
}

void Player::set_position(Vector2 position)
{
	rect.x = position.x;
	rect.y = position.y;
}

Vector2 Player::PlayerPart::get_position()
{
	return { rect.x, rect.y };
}

void Player::PlayerPart::set_position(Vector2 position)
{
	rect.x = position.x;
	rect.y = position.y;
}
