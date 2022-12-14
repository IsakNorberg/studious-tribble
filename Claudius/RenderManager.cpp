#include "SDL.h"
#include "RenderManager.h"

RenderManager::RenderManager(): _window("Snake"), _renderer(_window)
{
}

void RenderManager::render_buffer() noexcept
{
	_renderer.present();
	_renderer.clear();
	std::ranges::for_each(rect_buffer, [&](RectEntry& entry)
	{
		SDL_SetRenderDrawColor(_renderer._renderer.get(), entry.color.r, entry.color.g, entry.color.b, entry.color.a);
		SDL_Rect rect{ static_cast<int>(entry.trans.position.x),
				   static_cast<int>(entry.trans.position.y),
				   entry.rect.w,
				   entry.rect.h };
	SDL_RenderFillRect(_renderer._renderer.get(), &rect);  // <- If you want to draw a "filled" rectangle. 
	});
}

void RenderManager::add_to_render_buffer(const Rectangle& rect, const Color& color, const Transform& trans)
{
	rect_buffer.push_back({ rect, color, trans });
}

void RenderManager::clear_render_buffer() noexcept
{
	rect_buffer.clear();
}