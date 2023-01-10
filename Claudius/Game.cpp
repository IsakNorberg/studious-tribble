// 2019-12-05 Teemu Laiho

#include "Game.h"
#include <iostream>
void Game::run()
{
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
			case SDL_KEYDOWN: set_last_input(_event.key.keysym.sym); break;
		}
	}
}

void Game::apple_collision()
{
	if (_playerOne.get_head_position() == _apple.get_position())
	{
		_playerOne.player_score++;
		_apple.set_position({ (rand() % 125) * 10, (rand() % 70) * 10 });
	}
}

void Game::bunds_check()
{

	if (_playerOne.get_head_position().x > DEFAULT_WIDTH || _playerOne.get_head_position().x < 0||
		_playerOne.get_head_position().y > DEFAULT_HEIGHT || _playerOne.get_head_position().y < 0)
	{
		_lastInput = {};
		_playerOne.reset_player();
	}
}

void Game::update()
{
	_playerOne.move(_lastInput);
	bunds_check();
	apple_collision();
	// Player colliding on theirself.
	for (int i = 1; i < _playerOne.player_score; i++)
	{
		if (_playerOne.get_head_position() == _playerOne.parts[i].get_position())
		{
			_playerOne.reset_player();
		}
	}
}

void Game::render(RenderManager& renderManager)
{
	_playerOne.Render(renderManager);
	_apple.Render(renderManager);
}

void Game::set_last_input(SDL_Keycode key)
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

