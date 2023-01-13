#include "SDL.h"
#include "Game.h"
#include <iostream>
#undef main


int main()
{
	try{
		Game game;
		game.run();
	}
	catch (const SDLError& e) {
		std::cerr << "SDL initialization failure: " << e.what() << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Runtime error: " << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown error, exiting." << std::endl;
	}
	return 0;
}
