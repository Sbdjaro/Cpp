#pragma once
#include "SDL.h"
#include "Image.h"
#include <vector>

using namespace std;

class Game_over {
	SDL_Window* win;
	SDL_Surface* surface;
	int score;
	int time;
	SDL_Surface* img_end;
	vector<Image*> figures;
	vector<SDL_Rect*> rect_score;
	vector<SDL_Rect*> rect_time;
public:
	Game_over(SDL_Window*, SDL_Surface*);
	void Set(int, int);
	void Draw();
	~Game_over();
};