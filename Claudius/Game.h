#pragma once

#include <string_view>
#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"
#include "Window.h"

#include "Renderer.h"
#include "SDL.h"
#include "RenderManager.h"

constexpr Uint32 DELAY = 1000 / 20;

class Game final
{
	RenderManager _renderManager;
	Player _playerOne;
	Apple _apple;
	SDL_Event _event;

	SDL_Keycode _lastInput{};
	bool running{ true };
	void poll_events();
	void apple_collision();
	void bunds_check();
	void update();
	void render(RenderManager& rendererManager);
	void set_last_input(SDL_Keycode key);
public:
	void run(); 
};