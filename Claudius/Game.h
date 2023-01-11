#pragma once

#include <string_view>
#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "SDL.h"
#include "RenderManager.h"

constexpr Uint32 DELAY = 1000 / 20;

class Game final
{
	RenderManager _renderManager;
	Player _player;
	Apple _apple;
	SDL_Event _event{};

	bool running{ true };
	void poll_events() noexcept;
	void update() noexcept;
	void render(RenderManager& rendererManager);
	void collision() noexcept;

public:
	void run(); 
};
void seed_random() noexcept;
bool check_if_in_bunds(Vector2 position) noexcept;
