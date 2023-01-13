#include "Game.h"

void Game::run()
{
	seed_random();
	while (running)
	{
		poll_events();
		render(_renderManager);
		_renderManager.present();
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
	collisions();
	_player.update();
}

void Game::render(RenderManager& renderManager)
{
	_player.render(renderManager);
	_apple.Render(renderManager);
}

void Game::collisions() noexcept
{
	if (!check_if_in_bunds(_player.get_head_position(),DEFAULT_WIDTH, DEFAULT_HEIGHT)) [[unlikely]]
	{
		_player.reset();
	};  
	if (_player.collides_with_self())
	{
		_player.reset();
	}
	if (_apple.collision(_player.get_head_position())) [[unlikely]]
	{
		_player.add_part();
	}
}
void seed_random() noexcept
{
	srand(static_cast<int>(time(nullptr)));
}

[[nodiscard]] bool check_if_in_bunds(Vector2 position, int widthUpper, 
									 int heightUpper, int widthLower, int heightLower) noexcept
{
	if (position.x > widthUpper || position.x < widthLower ||
		position.y > heightUpper || position.y < heightLower) [[unlikely]]
	{
		return false;
	}
	return true;
}
