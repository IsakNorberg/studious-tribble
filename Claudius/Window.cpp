#include "Window.h"

void Window::center_window() const noexcept
{
	SDL_SetWindowPosition(_window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void Window::set_size(int width, int height) const noexcept
{
	SDL_SetWindowSize(_window.get(), width, height);
}


Window::Window(std::string_view title): _window()
{
	SDL_Window* ptr = SDL_CreateWindow(title.data(), 0, 0, 0, 0, 0);
	if (ptr == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
	_window = std::unique_ptr< SDL_Window, SDL_Deleter>(ptr);

	set_size(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	center_window();
}

SDL_Window* Window::getWindow() const noexcept
{
	return _window.get();
}
