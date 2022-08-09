#pragma once
#include "SDL.h"
#include <vector>
#include <list>
#include "Image.h"
#include "Const.h"
using namespace std;
class Enemy {
	
	
	int cur_time;
	int shoot_time;
	int x_, y_;
	int speed=0;
public:
	vector<int> position;// abs
	SDL_Rect* pose;
	Enemy(vector<int>);
	void Move();
	void Shoot();
	~Enemy();
};

class All_Enemy {
	list<Enemy*> enemies;
	SDL_Window* win;
	SDL_Surface* surface;
	Image* img;
public:
	All_Enemy(SDL_Window*, SDL_Surface*);
	void Draw();
	int Check_Enemy(vector<int>);
	vector<int> Get_near(int, int);
	void Kill(int);
	void Add();
	~All_Enemy();
};
