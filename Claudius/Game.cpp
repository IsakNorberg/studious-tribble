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

		_renderer.present();
		_renderer.clear();
		for (auto&& entry : renderManager.rectEntries)
		{
			SDL_SetRenderDrawColor(_renderer._renderer.get(), entry.color.r, entry.color.g, entry.color.b, entry.color.a);
			SDL_Rect rect{ static_cast<int>(entry.trans.position.x),
						   static_cast<int>(entry.trans.position.y),
						   entry.rect.w,
						   entry.rect.h };
			SDL_RenderFillRect(_renderer._renderer.get(), &rect);  // <- If you want to draw a "filled" rectangle. 
		}

		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}
}
Game::Game() : _gameWindow("Snake"), _renderer(_gameWindow)
{
	//SDL_Init(SDL_INIT_EVERYTHING);


	playerOne.Initialize();
	apple.Initialize(10, 10);
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
		if (playerOne.trans.GetPosition() == playerOne.parts[i].trans.GetPosition())
		{
			playerOne.ResetPlayer();
		}
	}

	// Player going out of X bounds.
	if (playerOne.trans.GetX() > DEFAULT_WIDTH || playerOne.trans.GetX() < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player going out of Y bounds.
	if (playerOne.trans.GetY() > DEFAULT_HEIGHT  || playerOne.trans.GetY() < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player collide on apple.
	if (playerOne.trans.GetPosition() == apple.trans.GetPosition())
	{
		playerOne.player_score++;
		apple.trans.SetPosition((rand() % 125) * 10.0f, (rand() % 70) * 10.0f);
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

