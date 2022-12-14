#pragma once
#include "Window.h"
#include "Renderer.h"
#include <algorithm>
#include <ranges>
#include <vector>
#include "Color.h"
#include "Transform.h"
#include "Rectangle.h"


struct RenderManager
{
	void clear_render_buffer() noexcept;
	RenderManager();
	Window _window;
	Renderer _renderer;
	struct RectEntry
	{
		const Rectangle& rect;
		const Color& color;
		const Transform& trans;
	};
	void render_buffer() noexcept;
	void add_to_render_buffer(const Rectangle& rect, const Color& color, const Transform& trans);
	
private:
	std::vector<RectEntry> rect_buffer;
};
