#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"
#include "Window.h"
#include "Sprite.h"
#include "Transform.h"
#include "Image.h"
#include "Window.h"
#include "Renderer.h"
#include "SDL.h"
#include "RenderManager.h"
#include <string_view>



class Game
{

	RenderManager renderManager;
	Player playerOne;
	Apple apple;

	bool running = true;
public:
	void run();
	Game();
	~Game(); 
	void Update();
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
};