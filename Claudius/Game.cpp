// 2019-12-05 Teemu Laiho

#include "Game.h"
#include <iostream>
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

void Game::poll_events()
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

void Game::apple_collision(Player& player)
{
	if (player.get_head_position() == _apple.get_position())
	{
		_apple.set_position(get_random_grid());
		player.add_part();
	}
}

void Game::check_if_player_is_in_bunds(Player& player)
{
	Vector2 position = player.get_head_position();
	if (position.x > DEFAULT_WIDTH || position.x < 0||
		position.y > DEFAULT_HEIGHT || position.y < 0)
	{
		player.reset();
	}
}

void Game::update()
{
	_player.update();
	check_if_player_is_in_bunds(_player);
	apple_collision(_player);
}

void Game::render(RenderManager& renderManager)
{
	_player.render(renderManager);
	_apple.Render(renderManager);
}

void Game::seed_random()
{
	srand(static_cast<int>(time(nullptr)));
}

Vector2 get_random_grid() noexcept
{
	return { (rand() % 125) * 10, (rand() % 70) * 10 };
}
