#pragma once
#include <SDL.h>
#include <vector>
#include "Person.h"
#include "Inventory.h"
#include <iostream>
#include "Ball.h"
#include "Enemy.h"
#include "My_ball.h"
#include "Panel.h"
using namespace std;
class Pole {
	vector<vector<char>> map;
	SDL_Surface* surface;
	SDL_Window* win;
	SDL_Surface* box_img;
	SDL_Surface* pol_img;
	SDL_Surface* dark_img;
	SDL_Rect* rect;
	SDL_Rect* midle;
	vector<vector<SDL_Rect*>> one;
	vector<vector<SDL_Rect*>> two;
	Person* person;
	My_ball* my_ball;
	
	bool check_x(int x);
	bool check_y(int y);

public:
	bool check_xy(vector<int>);
	bool check_trace(vector<int>, vector<int>);
	Panel* panel;
	Inventory* inventory;
	All_balls* balls;
	All_Enemy* enemies;
	int x;
	int y;
	Pole(SDL_Surface*,SDL_Window*);
	void Shoot(int,int);
	void Shoot_aim();
	void Draw(int,int);
	void Restart();
	~Pole();
};