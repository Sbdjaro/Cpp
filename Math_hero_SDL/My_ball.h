#pragma once
#include "Ball.h"
#include "SDL.h"

class My_ball {
	list<Ball*> balls;
	SDL_Window* win;
	SDL_Surface* surface;
	Image* img;
public:
	My_ball(SDL_Window*, SDL_Surface*);
	void Shoot(vector<int>);
	void Draw();
	void Restart();
	~My_ball();
};