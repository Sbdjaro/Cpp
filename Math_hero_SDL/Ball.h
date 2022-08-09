#pragma once
#include "SDL.h"
#include <vector>
#include <list>
#include "Image.h"
using namespace std;

class Ball {
	int side_x;
	int side_y;
	int time;
	int dmg;
	int cur_time;
	int speed;
	vector<int> location;
	
public:
	
	SDL_Rect* pose;
	Ball(int x, int y, int, int,int);
	~Ball();
	vector<int> Move();

};

class All_balls {
	list<Ball*> balls;
	SDL_Window* win;
	SDL_Surface* surface;
	Image* img;
public:
	All_balls(SDL_Window*, SDL_Surface*);
	void Add(int, int, int, int);
	void Draw();
	~All_balls();
};

