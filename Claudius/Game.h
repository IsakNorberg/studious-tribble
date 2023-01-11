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
	void poll_events();
	void apple_collision(Player& player);
	void check_if_player_is_in_bunds(Player& player);
	void update();
	void render(RenderManager& rendererManager);

	void seed_random();
public:
	void run(); 
};
Vector2 get_random_grid() noexcept;