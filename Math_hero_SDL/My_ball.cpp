#include "My_ball.h"
#include "Window.h"
My_ball::My_ball(SDL_Window* w, SDL_Surface* s): win(w),surface(s) {
	img = new Image("img/bomb_red.png");
}

void My_ball::Draw() {
	vector<int> tmp;
	vector<list<Ball*>::iterator> pp;
	for (auto i = balls.begin(); i != balls.end(); i++) {
		//cout << 1;
		tmp = (*i)->Move();

		if (!Window::me->pole->check_xy(tmp)) {
			pp.push_back(i);
			continue;
		}
		//cout << tmp[0] << " " << tmp[1] << "\n";
		//tmp[0] -= Window::me->pole->x;
		//tmp[1] -= Window::me->pole->y;
		//cout << tmp[0] << " " << tmp[1] << "\n\n";
		int j = Window::me->pole->enemies->Check_Enemy(tmp);
		if (j!=-1) {
			Window::me->pole->enemies->Kill(j);
			pp.push_back(i);
			//cout << "Kill\n";
			continue;
		}
		SDL_BlitSurface(img->img, nullptr, surface, (*i)->pose);
	}
	for (int i = 0; i < (int)pp.size(); i++) {
		delete* pp[i];
		balls.erase(pp[i]);
		//Add(rand() % 1000, rand() % 1000, rand() % 5, rand() % 5);
	}
}

void My_ball::Restart(){
	for (auto i = balls.begin(); i != balls.end(); i++)
		delete* i;
	balls.clear();
}

void My_ball::Shoot(vector<int> side) {
	// Разные пушки
	balls.push_back(new Ball( side[0], side[1], side[2], side[3],5 ));
	//cout << "My_ball::Shoot\n";
}


My_ball::~My_ball() {
	for (auto i = balls.begin(); i != balls.end(); i++)
		delete* i;
	delete img;
}