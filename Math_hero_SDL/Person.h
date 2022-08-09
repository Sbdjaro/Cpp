#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Image.h"
#include <vector>
using namespace std;
class Person {
	SDL_Window* win;
	SDL_Surface* surface;
	vector<vector<Image*>> images;
	int cur_type = 0;
	int point = 0;
	int time = 9;
	int cur_time = 0;
	SDL_Rect* midle;
public:
	Image* img;
	Person(SDL_Window*, SDL_Surface*);
	void Draw(int);
	void Restart();
	~Person();
};