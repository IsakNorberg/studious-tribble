#pragma once

#include <string_view>
#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"
#include "Window.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL.h"
#include "RenderManager.h"


class Game
{
	RenderManager _renderManager;
	Player _playerOne;
	Apple _apple;
	SDL_Event _event;
	bool running{ true };
public:
	void run(); 
	void Update();
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
};