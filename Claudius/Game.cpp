// 2019-12-05 Teemu Laiho

#include "Game.h"
#include <iostream>
void Game::run()
{
	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				case SDL_QUIT: running = false; break;
				case SDL_KEYDOWN: OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
			}
		}

		Update();
		Render(renderManager);
		renderManager.render_buffer();


		SDL_Delay(1000 / 20); //<- "Framerate".
	}
}
Game::Game()
{
}

Game::~Game()
{
}


void Game::Update()
{
	
	playerOne.Update();

	// Player colliding on theirself.
	for (int i = 0; i < playerOne.player_score; i++)
	{
		if (playerOne.get_position() == playerOne.parts[i].get_position())
		{
			playerOne.ResetPlayer();
		}
	}

	// Player going out of X bounds.
	if (playerOne.get_position().x > DEFAULT_WIDTH || playerOne.get_position().x < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player going out of Y bounds.
	if (playerOne.get_position().y > DEFAULT_HEIGHT || playerOne.get_position().y < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player collide on apple.
	if (playerOne.get_position() == apple.get_position())
	{
		playerOne.player_score++;
		apple.set_position({ (rand() % 125) * 10, (rand() % 70) * 10 });
	}
}

void Game::Render(RenderManager& renderManager)
{
	playerOne.Render(renderManager);
	apple.Render(renderManager);
}

void Game::OnKeyDown(KeyCode key)
{
	playerOne.OnKeyDown(key);
}

