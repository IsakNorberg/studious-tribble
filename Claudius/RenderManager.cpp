#include "SDL.h"
#include "RenderManager.h"

RenderManager::RenderManager(): _window(name), _renderer(_window)
{
}

void RenderManager::render_buffer() noexcept
{
	_renderer.present();
	_renderer.clear();
}

void RenderManager::add_to_render_buffer(SDL_Rect rect, SDL_Color color)
{
	SDL_SetRenderDrawColor(_renderer.get_render_pointer(), color.r, color.g, color.b, color.a);
	SDL_Rect årect{ static_cast<int>(trans.position.x), static_cast<int>(trans.position.y),rect.w, rect.h };
	SDL_RenderFillRect(_renderer.get_render_pointer(), &årect);
}
