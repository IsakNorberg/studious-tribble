#pragma once
#include "Window.h"
#include "Renderer.h"
#include <algorithm>
#include <ranges>
#include <vector>
#include <string_view>
#include "Vector2.h"

constexpr std::string_view NAME = "Snake";
constexpr int WHITH = 10;
constexpr int HEIGHT = 10;
constexpr SDL_Color GREEN = { 0, 255, 0, 0 };


class RenderManager final
{
	Window _window{NAME};
	Renderer _renderer{_window};

public:
	void render_buffer() noexcept;
	void add_to_render_buffer(Vector2 position, SDL_Color color = GREEN)const noexcept;
};
