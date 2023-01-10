#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>


void Player::move(Vector2 direction)
{
	//change_position(direction);
	parts[0].change_position(direction);

	for (int i = 2; i < player_size; i++)
	{
		parts[i].change_position({ x_array_difference[i - 1], y_array_difference[i - 1] });
	}
}

void Player::Render(RenderManager& renderManager)
{
	//renderManager.add_to_render_buffer(_position, _color);

	for (int i = 0; i < player_score; i++)
	{
		renderManager.add_to_render_buffer(parts[i].get_position());
	}
}

void Player::move(SDL_Keycode input) noexcept
{
	x_array_difference[1] = parts[0].get_position().x - parts[1].get_position().x;
	y_array_difference[1] = parts[0].get_position().y - parts[1].get_position().y;

	for (int i = 1; i < player_size - 1; i++)
	{
			x_array_difference[i] = parts[i].get_position().x - parts[i + 1].get_position().x;
			y_array_difference[i] = parts[i].get_position().y - parts[i + 1].get_position().y;
	}

	switch (input)
	{
		case SDLK_UP: move(UP); break;
		case SDLK_DOWN: move(DOWN); break;
		case SDLK_LEFT: move(LEFT); break;
		case SDLK_RIGHT: move(RIGHT); break;
		default: return; break;
	}

}


void Player::reset_player() noexcept
{
	player_score = 1;

	set_head_position(STARTING_POSITION);
}

Vector2 Player::get_head_position() const noexcept
{
	return parts[0].get_position();
}

void Player::set_head_position(Vector2 position)noexcept
{
	parts[0].set_position(position);
}

//void Player::change_position(Vector2 position)noexcept
//{
//	position = position + get_position();
//	set_position(position);
//}

Vector2 PlayerPart::get_position()const noexcept
{
	return _position;
}

void PlayerPart::set_position(Vector2 position)noexcept
{
	_position = position;
}

void PlayerPart::change_position(Vector2 position)noexcept
{
	position = position + get_position();
	set_position(position);
}
