#include "Renderer.h"

SDL_Renderer* Renderer::get_pointer() const noexcept
{
	return _renderer.get();
}

Renderer::Renderer(const Window& window) {
	_renderer = std::unique_ptr<SDL_Renderer, SDL_Deleter>(SDL_CreateRenderer(window.get_pointer(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED));
	if (_renderer == nullptr) [[unlikely]]
	{
		throw SDLError();
	}
}

void Renderer::clear() const noexcept
{
	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, MAX_ALPHA);
	SDL_RenderClear(_renderer.get());
}

void Renderer::present() const noexcept
{
	SDL_RenderPresent(_renderer.get());
}
