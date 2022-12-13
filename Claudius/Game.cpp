// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game()
{
	//Player test, moving two players to collide with each other.
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

