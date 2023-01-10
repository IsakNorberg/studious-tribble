// 2019-12-05 Teemu Laiho

#include "Game.h"
#include <iostream>
void Game::run()
{
	while (running)
	{
		
		while (SDL_PollEvent(&_event))
		{
			switch (_event.type)
			{
				case SDL_QUIT: running = false; break;
				case SDL_KEYDOWN: OnKeyDown(TranslateKeyCode(_event.key.keysym.sym)); break;
			}
		}

		Update();
		Render(_renderManager);
		_renderManager.render_buffer();


		SDL_Delay(1000 / 20); //<- "Framerate".
	}
}

void Game::Update()
{
	
	_playerOne.Update();

	// Player colliding on theirself.
	for (int i = 0; i < _playerOne.player_score; i++)
	{
		if (_playerOne.get_position() == _playerOne.parts[i].get_position())
		{
			_playerOne.ResetPlayer();
		}
	}

	// Player going out of X bounds.
	if (_playerOne.get_position().x > DEFAULT_WIDTH || _playerOne.get_position().x < 0)
	{
		_playerOne.ResetPlayer();
	}

	// Player going out of Y bounds.
	if (_playerOne.get_position().y > DEFAULT_HEIGHT || _playerOne.get_position().y < 0)
	{
		_playerOne.ResetPlayer();
	}

	// Player collide on apple.
	if (_playerOne.get_position() == _apple.get_position())
	{
		_playerOne.player_score++;
		_apple.set_position({ (rand() % 125) * 10, (rand() % 70) * 10 });
	}
}

void Game::Render(RenderManager& renderManager)
{
	_playerOne.Render(renderManager);
	_apple.Render(renderManager);
}

void Game::OnKeyDown(KeyCode key)
{
	_playerOne.OnKeyDown(key);
}

