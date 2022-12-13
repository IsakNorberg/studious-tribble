#pragma once
#include "SDL.h"
#include <memory>
#include "Window.h"

class Renderer
{
	
public:
	std::unique_ptr<SDL_Renderer,SDL_Deleter> _renderer;
public:
	Renderer(const Window& window);
	void clear() const noexcept;
	void present() const noexcept;
};