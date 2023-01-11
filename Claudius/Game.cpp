#include "Game.h"

void Game::run()
{
	seed_random();
	while (running)
	{
		poll_events();
		render(_renderManager);
		_renderManager.render_buffer();
		update();
		SDL_Delay(DELAY);
	}
}

void Game::poll_events() noexcept
{
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
			[[unlikely]] case SDL_QUIT: running = false; break;
			[[unlikely]] case SDL_KEYDOWN: _player.set_last_input(_event.key.keysym.sym); break;
			[[likely]] default: continue; break;
		}
	}
}

void Game::update() noexcept
{
	collision();
	_player.update();
}

void Game::render(RenderManager& renderManager)
{
	_player.render(renderManager);
	_apple.Render(renderManager);
}

void Game::collision() noexcept
{
	if (!check_if_in_bunds(_player.get_head_position())) [[unlikely]]
	{
		_player.reset();
	};                
	if (_apple.collision(_player.get_head_position())) [[unlikely]]
	{
		_player.add_part();
	}
}
void seed_random() noexcept
{
	srand(static_cast<int>(time(nullptr)));
}

[[nodiscard]] bool check_if_in_bunds(Vector2 position) noexcept
{
	if (position.x > DEFAULT_WIDTH || position.x < 0 ||
		position.y > DEFAULT_HEIGHT || position.y < 0) [[unlikely]]
	{
		return false;
	}
	return true;
}
