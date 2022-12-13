#include "SDL.h"
#include "RenderManager.h"


struct RenderImpl
{
	SDL_Renderer* renderer;
};

void RenderManager::Render(const Sprite& sprite, const Transform& trans)
{
}

void RenderManager::Render(const Rectangle& rect, const Color& color, const Transform& trans)
{
	rectEntries.push_back({ rect, color, trans });
}

void RenderManager::Clear()
{
	rectEntries.clear();
}