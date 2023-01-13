#pragma once
#include "Settings.h"

#include <string_view>
#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"

#include "RenderManager.h"



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
	void collisions() noexcept;

public:
	void run(); 
};
void seed_random() noexcept;
[[nodiscard]] bool check_if_in_bunds(Vector2 position, int widthUpper, int heightUpper, int widthLower = 0, int heightLower = 0) noexcept;
