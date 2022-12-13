#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"
#include "Window.h"

struct RenderManager;
struct ResourceManager;

class Game
{
	Player playerOne;
	Apple apple;

public:
	Game();
	~Game(); 
	void Update();
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
};