#include "Renderer.h"

SDL_Renderer* Renderer::get_render_pointer()
{
	return _renderer.get();
}

Renderer::Renderer(const Window& window)
{
	SDL_Renderer* ptr = SDL_CreateRenderer(window.getWindow(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (ptr == nullptr)
	{
		throw std::runtime_error(SDL_GetError());
	}
	_renderer = std::unique_ptr<SDL_Renderer, SDL_Deleter>(ptr);
}

void Renderer::clear() const noexcept
{
	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 0);
	SDL_RenderClear(_renderer.get());
}

void Renderer::present() const noexcept
{
	SDL_RenderPresent(_renderer.get());
}
