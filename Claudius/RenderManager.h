#pragma once
#include "Settings.h"

#include "Window.h"
#include "Renderer.h"
#include <algorithm>
#include <ranges>
#include <vector>
#include <string_view>


class RenderManager final
{
	Window _window{NAME};
	Renderer _renderer{_window};

public:
	void present() noexcept;
	void draw(Vector2 position, SDL_Color color = GREEN)const noexcept;
};
