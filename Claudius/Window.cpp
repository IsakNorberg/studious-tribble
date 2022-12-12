#include "Window.h"

void window::center() noexcept
{
	SDL_SetWindowPosition(_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void window::set_size(int width, int height)
{
	SDL_SetWindowSize(_window, width, height);
}

void window::set_titel(std::string_view title)
{
	SDL_SetWindowTitle(_window, title.data());
}

window::window()
{
	_window = SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
}

window::~window()
{
	SDL_DestroyWindow(_window);
}
