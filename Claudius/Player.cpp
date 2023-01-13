#include "Player.h"


void Player::move(Vector2 direction) noexcept
{
	for (PlayerPart& part: parts| std::views::reverse)
	{		
		if (part == get_head_position())
		{
			continue;
		}
		part = *(&part - 1);
	}
	parts[0] += direction; // parts[0] is the head
}

bool Player::collides_with_self() const noexcept
{
	auto start = parts.begin() + 1;
	const auto pos = get_head_position();
	auto result = std::find_if(start, parts.end(), [pos](PlayerPart part)
	{		
		return part == pos;
	});
	if (result != parts.end()) [[unlikely]]
	{
		return true;
	};
	return false;
}

void Player::set_last_input(SDL_Keycode key) noexcept
{
	switch (key)
	{
		case SDLK_UP: _direction =UP; break;
		case SDLK_DOWN: _direction = DOWN; break;
		case SDLK_LEFT: _direction = LEFT; break;
		case SDLK_RIGHT: _direction = RIGHT; break;
		[[unlikely]] default: return; break;
	}
}

void Player::render(const RenderManager& r) const
{
	for (const auto& part : parts)
	{
		r.draw(part);
	}
	r.draw(parts[0], RED);
}

void Player::update() noexcept
{
	collides_with_self();	
	move(_direction);
}

void Player::reset() noexcept
{
	_direction = {};
	parts.resize(1);
	set_head_position(STARTING_POSITION);
}

void Player::add_part() noexcept
{
	parts.push_back(PlayerPart());
}

Vector2 Player::get_head_position() const noexcept
{
	return parts[0];
}

void Player::set_head_position(Vector2 position)noexcept
{
	parts[0] = position;
}
