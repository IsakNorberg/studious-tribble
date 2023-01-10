#include "SDL.h"
#include "RenderManager.h"

void RenderManager::render_buffer() noexcept
{
	_renderer.present();
	_renderer.clear();
}

void RenderManager::add_to_render_buffer(Vector2 position, SDL_Color color) const noexcept
{
	SDL_SetRenderDrawColor(_renderer.get_pointer(), color.r, color.g, color.b, color.a);
	SDL_Rect rect = { position.x, position.y, WHITH, HEIGHT };
	SDL_RenderFillRect(_renderer.get_pointer(), &rect);
}
