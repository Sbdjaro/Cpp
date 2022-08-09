#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
using namespace std;
class Inventory {
	SDL_Surface* surface;
	SDL_Window* win;

	SDL_Surface* img_hotbar;
	SDL_Surface* img_hotbar_active;
	vector<SDL_Rect*> rect_hotbar_cell;
	int active_hotbar=0;
public:
	Inventory(SDL_Window*, SDL_Surface*);
	void Draw();
	void Change_hotbar();
	void Restart();
	~Inventory();
};