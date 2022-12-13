#include "Renderer.h"

Renderer::Renderer(const Window& window)
{
	SDL_Renderer* ptr = SDL_CreateRenderer(window.getWindow(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (ptr == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
	_renderer = std::unique_ptr<SDL_Renderer, SDL_Deleter>(ptr);
}
