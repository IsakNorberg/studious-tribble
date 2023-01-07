#pragma once

#include <string_view>
#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"
#include "Window.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL.h"
#include "RenderManager.h"




class Game
{
	RenderManager renderManager;
	Player playerOne;
	Apple apple{10,10};

	bool running = true;
public:
	void run();
	Game();
	~Game(); 
	void Update();
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
};