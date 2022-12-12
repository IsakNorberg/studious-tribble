#pragma once
#include "SDL.h"
#include <memory>
#include <string_view>

constexpr int DEFAULT_WIDTH = 500;
constexpr int DEFAULT_HEIGHT = 500;

class window
{
	SDL_Window* _window;
public:
	void center() noexcept;
	void set_size(int width, int height);
	void set_titel(std::string_view title);
	window();
	window(const window& w) = delete;
	window(const window&& w) = delete;
	window operator=(window&& rhs) = delete;
	window operator=(window& rhs) = delete;
		
	~window();

};