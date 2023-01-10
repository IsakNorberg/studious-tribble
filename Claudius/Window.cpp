#include "Window.h"

Window::Window(std::string_view title)
{
	_window = std::unique_ptr< SDL_Window, SDL_Deleter>(SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WIDTH, DEFAULT_HEIGHT, 0));
	if (_window == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
}

SDL_Window* Window::get_pointer() const noexcept
{
	return _window.get();
}
