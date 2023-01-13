#pragma once
#include "Deleter.h"
#include <memory>
#include <string_view>
#include "Settings.h"

class Window final
{
	std::unique_ptr<SDL_Window, SDL_Deleter> _window;
public:
	Window(std::string_view title);
	SDL_Window* get_pointer() const noexcept;
};