#include "Player.h"

void Player::move(Vector2 direction)
{
	parts[0].move_in_direction(direction);
	for (PlayerPart& part: parts| std::views::reverse)
	{
		if (part.get_position() == parts[0].get_position())
		{
			return;
		}
		part.set_position((&part - 1)->get_position());
	}
}

void Player::collides_with_self() noexcept
{
	using reverse_iterator = std::vector<PlayerPart>::reverse_iterator;
	reverse_iterator head(parts.begin());
	reverse_iterator end(parts.end());
	auto result = std::find_if(end, head, [&](PlayerPart part)
	{
		return part.get_position() == get_head_position();
	});
	if (result != head)
	{
		reset();
	};
}

void Player::set_last_input(SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_UP: _lastInput = key; break;
		case SDLK_DOWN: _lastInput = key; break;
		case SDLK_LEFT: _lastInput = key; break;
		case SDLK_RIGHT: _lastInput = key; break;
		default: return; break;
	}
}

void Player::render(RenderManager& renderManager)
{
	for (PlayerPart& part : parts)
	{
		renderManager.add_to_render_buffer(part.get_position());
	}
	renderManager.add_to_render_buffer(parts[0].get_position(), RED);
}

void Player::update() noexcept
{
	collides_with_self();
	switch (_lastInput)
	{
		case SDLK_UP: move(UP); break;
		case SDLK_DOWN: move(DOWN); break;
		case SDLK_LEFT: move(LEFT); break;
		case SDLK_RIGHT: move(RIGHT); break;
		default: return; break;
	}
}


void Player::reset() noexcept
{
	_lastInput = {};
	parts.reserve(1);
	set_head_position(STARTING_POSITION);
}

void Player::add_part() noexcept
{
	parts.push_back(PlayerPart());
}

Vector2 Player::get_head_position() const noexcept
{
	return parts[0].get_position();
}

void Player::set_head_position(Vector2 position)noexcept
{
	parts[0].set_position(position);
}


Vector2 PlayerPart::get_position()const noexcept
{
	return _position;
}

void PlayerPart::set_position(Vector2 position)noexcept
{
	_position = position;
}

void PlayerPart::move_in_direction(Vector2 position)noexcept
{
	position = position + get_position();
	set_position(position);
}
