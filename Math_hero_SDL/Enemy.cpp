#include "Enemy.h"
#include "Window.h"

Enemy::Enemy(vector<int> v) : position(v), pose(new SDL_Rect{ v[0] - 12 - Window::me->pole->x + 500,
	v[1] - 12 - Window::me->pole->y + 500, 25, 25 }) {
	cur_time = rand()%SHOOT_SPEED;
	shoot_time = SHOOT_SPEED;
	speed = rand() % 200;
	
}

void Enemy::Shoot() {
	if (cur_time == shoot_time) {
		cur_time = 0;
		Window::me->pole->balls->Add(position[0], position[1], Window::me->pole->x- position[0],
			Window::me->pole->y - position[1]);
	}
	cur_time++;
}

void Enemy::Move() {
	Pole* p = Window::me->pole;
	delete pose;
	pose = new SDL_Rect{ position[0] - 12 - p->x + 500,
			position[1] - 12 - p->y + 500, 25, 25 };
	if (speed%ENEMY_SPEED!=0) {
		
		speed++;
		return;
	}
	if (speed == 200) {
		x_ = rand() % 3 - 1;
		y_ = rand() % 3 - 1;
		speed = 0;
	}
	speed++;
	Shoot();
	
	int x, y;
	x = position[0] - p->x;
	y = position[1] - p->y;
	if (x * x + y * y > 100000 || !p->check_trace(position, { p->x ,p->y})) {
		x = x_;
		y = y_;
		if (speed > 150)
			return;
	}
	x = -x / max(1,abs(x));
	y = -y / max(1,abs(y));
	if (x* x + y * y == 2) {
		if (rand() % 2) {
			x *= 3;
			y *= 4;
		}
		else {
			y *= 3;
			x *= 4;
		}
	}
	else {
		x *= 5;
		y *= 5;
	}
	position[0] += x;
	position[1] += y;
	if (!Window::me->pole->check_xy(position)) {
		position[0] -= 2*x;
		position[1] -= 2*y;
		x_ *= -1;
		y_ *= -1;
		
	}
	if (!Window::me->pole->check_xy(position)) {
		position[0] += x;
		position[1] += y;
		return;
	}
	delete pose;
	pose = new SDL_Rect{ position[0] - 12 - p->x + 500,
		position[1] - 12 - p->y + 500, 25, 25 };
	return;
	
}

Enemy::~Enemy() {
	delete pose;
}

All_Enemy::All_Enemy(SDL_Window* w, SDL_Surface* s):surface(s),win(w) {
	img = new Image("img/Pudge.png");
}

void All_Enemy::Draw() {
	vector<int> tmp;
	vector<list<Enemy*>::iterator> pp;
	while (enemies.size() < 5)
		Add();
	for (auto i = enemies.begin(); i != enemies.end(); i++) {
		//cout << 1;
		(*i)->Move();
		SDL_BlitSurface(img->img, nullptr, surface, (*i)->pose);
	}
}

int All_Enemy::Check_Enemy(vector<int> v)
{	
	int k = 0;
	for (auto i = enemies.begin(); i != enemies.end(); i++,k++) {
		if (v[0] > (*i)->position[0] - 20 && v[0] < (*i)->position[0] + 20 &&
			v[1]>(*i)->position[1] - 20 && v[1] < (*i)->position[1] + 20)
			return k;
	}
	return -1;
}

vector<int> All_Enemy::Get_near(int x, int y) {
	long range = (long)1E9;
	long tmp;
	vector<int> v = { 0,-1 };
	for (auto i = enemies.begin(); i != enemies.end(); i++) {
		//cout << (*i)->position[0] << " " << (*i)->position[1] << "\n";
		tmp = ((*i)->position[0] - x)* ((*i)->position[0] - x) + ((*i)->position[1] - y)* ((*i)->position[1] - y);
		//cout << tmp << "\n";
		if (tmp < range) {
			if (Window::me->pole->check_trace({ x,y }, { (*i)->position[0],(*i)->position[1] })) {
				range = tmp;
				v = (*i)->position;
			}
		}
	}
	return v;
}

void All_Enemy::Kill(int k)
{	
	auto j = enemies.begin();
	for (int i = 0; i < k; i++,j++);
	delete *j;
	enemies.erase(j);
	Window::me->pole->panel->score->Add();
}

void All_Enemy::Add() {
	vector<int> tmp;
	//cout << "WOW\n";
	while (1) {
		//cout << "WO))))W\n";
		tmp = { rand() % 1500,rand() % 1500 };
		if (Window::me->pole->check_xy(tmp)) {
			//cout << "WOW1\n";
			enemies.push_back(new Enemy{ tmp });
			//cout << "WOW12\n";
			return;
		}
	}
}

All_Enemy::~All_Enemy(){
	delete img;
	auto iter = enemies.begin();
	while (iter != enemies.end())
	{
		delete* iter;
		iter++;
	}
}
