#pragma once
#include "Window.h"
#include "Renderer.h"
#include <algorithm>
#include <ranges>
#include <vector>
#include "Color.h"
#include "Transform.h"
#include "Rectangle.h"
#include <string_view>

constexpr std::string_view name = "Snake";

class RenderManager
{
	Window _window;
	Renderer _renderer;

public:
	RenderManager();
	void render_buffer() noexcept;
	void add_to_render_buffer(SDL_Rect rect, SDL_Color color);
	
private:

};
