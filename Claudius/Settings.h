#pragma once
#include <stdexcept>
#include "SDL.h"
#include "Vector2.h"

struct SDLError : std::runtime_error {
	SDLError() : std::runtime_error(SDL_GetError()) {};
};

constexpr Uint32 DELAY = 1000 / 20;
constexpr int MOVEMENT_SPEED = 10;
constexpr Vector2 STARTING_POSITION = { 300, 300 };
constexpr SDL_Color RED = { 255,0,0,0 };
constexpr Vector2 UP = { 0,-MOVEMENT_SPEED };
constexpr Vector2 DOWN = { 0,MOVEMENT_SPEED };
constexpr Vector2 RIGHT = { MOVEMENT_SPEED, 0 };
constexpr Vector2 LEFT = { -MOVEMENT_SPEED, 0 };
constexpr int MAX_ALPHA = 255;
constexpr std::string_view NAME = "Snake";
constexpr int WIDTH = 10;
constexpr int HEIGHT = 10;
constexpr SDL_Color GREEN = { 0, 255, 0, 255 };
constexpr int DEFAULT_WIDTH = 1250;
constexpr int DEFAULT_HEIGHT = 700;
constexpr Vector2 APPLE_START_POSITION = { 100,200 };
constexpr int GRID_AMUNT_Y = 70;
constexpr int GRID_AMUNT_X = 125;
constexpr int GRID_SIZE = 10;
