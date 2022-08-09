#pragma once
#include "SDL.h"
#include "Image.h"
#include <vector>
#include <string>
using namespace std;

class Score {

	SDL_Window* win;
	SDL_Surface* surface;
	vector<Image*>* figures;
	Image* img_score;
	SDL_Rect* rect_score;
	vector<SDL_Rect*> rect_figures;
	
public:
	int score = 0;
	Score(SDL_Window*, SDL_Surface*, vector<Image*>*);
	void Draw();
	void Add();
	void Restart();
	~Score();
};

class Health {

	SDL_Window* win;
	SDL_Surface* surface;
	vector<Image*>* figures;
	Image* img_health;
	SDL_Rect* rect_health;
	vector<SDL_Rect*> rect_figures;
	int health = 100;
public:
	Health(SDL_Window*, SDL_Surface*, vector<Image*>*);
	void Draw();
	void Add(int x);
	void Sub();
	void Restart();
	~Health();
};


class Panel {
	SDL_Window* win;
	SDL_Surface* surface;
	vector<Image*> figures;
	vector<Image*> img_sign;
	SDL_Rect* rect_figures;
	int task;
	int task1;
	int task2;
	bool plus;
	int current;
	bool cur_sign=false;
	vector<SDL_Rect*> rect_task;
	vector<SDL_Rect*> rect_answer;
	void Generate();
	
public:
	Score* score;
	Health* health;
	Panel(SDL_Window*, SDL_Surface*);
	void Draw();
	void Check();
	void Minus();
	void Add(int);
	void Restart();
	~Panel();
};


