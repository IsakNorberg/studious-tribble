#include "SDL.h"
#include "RenderManager.h"
#include "Game.h"
#include "Sprite.h"
#include "Transform.h"
#include "Image.h"
#include "Window.h"
#include "Renderer.h"
#include <string_view>
#undef main

int main()
{
	//SDL_Init(SDL_INIT_EVERYTHING);
	Window gameWindow("Snake");
	Renderer renderer(gameWindow);
	
	bool running = true;
	RenderManager renderManager;
	Game game;
	
	float dt = 1.0f / 60.0f;
	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: game.OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
			}
		}

		game.Update();
		game.Render(renderManager);

		renderer.present();
		renderer.clear();
		for (auto&& entry : renderManager.rectEntries)
		{
			SDL_SetRenderDrawColor(renderer._renderer.get(), entry.color.r, entry.color.g, entry.color.b, entry.color.a);
			SDL_Rect rect{ static_cast<int>(entry.trans.position.x),
						   static_cast<int>(entry.trans.position.y),
						   entry.rect.w,
						   entry.rect.h };
			SDL_RenderFillRect(renderer._renderer.get(), &rect);  // <- If you want to draw a "filled" rectangle. 
		}
		
		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}

	return 0;
}
