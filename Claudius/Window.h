#pragma once
#include "Deleter.h"
#include <memory>
#include <string_view>
#include <stdexcept>

constexpr int DEFAULT_WIDTH = 1250;
constexpr int DEFAULT_HEIGHT = 700;

class Window
{
	std::unique_ptr<SDL_Window, SDL_Deleter> _window;
	void center_window() noexcept;
public:
	void set_size(int width, int height);
	Window(std::string_view title);
	SDL_Window* getWindow() const noexcept;
};