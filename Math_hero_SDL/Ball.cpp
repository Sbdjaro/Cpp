#include "Ball.h"
#include "Window.h"

All_balls::All_balls(SDL_Window* w, SDL_Surface* s):win(w),surface(s){
	img = new Image("img/bomb.png");
	//Add(100, 100, 1, 0);
	//for (int i = 0; i < 10; i++) {
	//	Add(rand() % 1000, rand() % 1000, rand() % 5, rand() % 5);
	//}
}

void All_balls::Add(int x, int y, int z, int a) {
	balls.push_back(new Ball(x, y, z, a,2));
}

All_balls::~All_balls() {
	auto iter = balls.begin();
	while (iter!=balls.end())
	{
		delete* iter;
		iter++;
	}
	delete img;
}

void All_balls::Draw() {
	//cout << balls.size() << "\n";
	//if (balls.begin() == balls.end())
	//	cout << "TRUE\n";
	//else
	//	cout << "False\n";
	vector<int> tmp;
	vector<list<Ball*>::iterator> pp;
	
	for (auto i = balls.begin(); i != balls.end(); i++) {
		//cout << balls.size() << "\n";
		tmp = (*i)->Move();
		
		if (!Window::me->pole->check_xy(tmp)) {
			pp.push_back(i);
			continue;
		}
		//cout << tmp[0] << " " << tmp[1] << "\n";
		tmp[0] -= Window::me->pole->x;
		tmp[1] -= Window::me->pole->y;
		//cout << tmp[0] << " " << tmp[1] << "\n\n";
		if (tmp[0] > -10 && tmp[0] < 10 && tmp[1]>-20 && tmp[1] < 20) {
			pp.push_back(i);
			//cout << "WOW";
			Window::me->pole->panel->health->Sub();
			if (balls.size() == 0)
				return;
			continue;
		}
		SDL_BlitSurface(img->img, nullptr, surface, (*i)->pose);
	}
	for (int i = 0; i < (int)pp.size(); i++) {
		delete *pp[i];
		balls.erase(pp[i]);
		//Add(rand() % 1000, rand() % 1000, rand() % 5, rand() % 5);
	}
	//cout << 2;
}

void All_balls::Restart(){
	auto iter = balls.begin();
	while (iter != balls.end())
	{
		delete* iter;
		iter++;
	}
	balls.clear();
	balls = list<Ball*>();
}


Ball::Ball(int x, int y, int z, int a,int speed_ = 2):side_x(z),side_y(a), location(2,0), pose(nullptr),speed(speed_) {
	cur_time = 0;
	location[0] = x;
	location[1] = y;
	time = max(1,(int)sqrt(z * z + a * a));
	side_x *= 7;
	side_y *= 7;
	side_x /= time;////////////////////////////////////////////////////////////////division by zero side_x = side_x/time
	side_y /= time;
	time = (int)sqrt(side_x * side_x + side_y * side_y) ;
	//cout << time;
}

Ball::~Ball() {
	delete pose;
}

vector<int> Ball::Move() {
	if (cur_time == time) {
		cur_time = 0;
		location[0] += side_x*speed;
		location[1] += side_y*speed;
	}
	delete pose;
	pose = new SDL_Rect{ location[0] - 2-Window::me->pole->x+500,location[1] - 2 - Window::me->pole->y+500,5,5 };
	cur_time++;
	return location;
}