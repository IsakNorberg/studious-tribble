#include "Game.h"

void Game::run()
{
	seed_random();
	while (running)
	{
		poll_events();
		update();
		render(_renderManager);
		_renderManager.render_buffer();
		SDL_Delay(DELAY);
	}
}

void Game::poll_events() noexcept
{
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: _player.set_last_input(_event.key.keysym.sym); break;
			default: continue; break;
		}
	}
}

void Game::update() noexcept
{
	_player.update();
	collision();
}

void Game::render(RenderManager& renderManager)
{
	_player.render(renderManager);
	_apple.Render(renderManager);
}

void Game::collision() noexcept
{
	if (!check_if_in_bunds(_player.get_head_position()))
	{
		_player.reset();
	};                
	if (_apple.collision(_player.get_head_position()))
	{
		_player.add_part();
	}
}
void seed_random() noexcept
{
	srand(static_cast<int>(time(nullptr)));
}

bool check_if_in_bunds(Vector2 position) noexcept
{
	if (position.x > DEFAULT_WIDTH || position.x < 0 ||
		position.y > DEFAULT_HEIGHT || position.y < 0)
	{
		return false;
	}
	return true;
}
