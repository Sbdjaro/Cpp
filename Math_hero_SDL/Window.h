#pragma once
#include <iostream>
#include <SDL.h>

#include "Pole.h"
#include "Gamestats.h"
#include "Game_over.h"
class Window {

	static const int SCREEN_WIDTH = 1000;
	static const int SCREEN_HEIGHT = 1000;
	SDL_Window* window{ nullptr };
	SDL_Surface* pause{ nullptr };
public:
	SDL_Surface* surface{ nullptr };
	Stats* stats;
	Pole* pole;
	Game_over* game_over;
	static Window* me;
	Window();
	bool Pause();
	void Game();
	void End_game();

	~Window();

};
