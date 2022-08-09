#include "Person.h"

Person::Person(SDL_Window* w,SDL_Surface*s):win(w),surface(s),images(4,vector<Image*>(6,nullptr)) {
	midle = new SDL_Rect{ 483, 475, 525, 525 };
	img = new Image("img/move1.png");
	images[0][0] = new Image("img/move/down/move0.png");
	images[0][1] = new Image("img/move/down/move1.png");
	images[0][2] = new Image("img/move/down/move2.png");
	images[0][3] = new Image("img/move/down/move3.png");
	images[0][4] = new Image("img/move/down/move4.png");
	images[0][5] = new Image("img/move/down/move5.png");

	images[1][0] = new Image("img/move/left/0.png");
	images[1][1] = new Image("img/move/left/1.png");
	images[1][2] = new Image("img/move/left/2.png");
	images[1][3] = new Image("img/move/left/3.png");
	images[1][4] = new Image("img/move/left/4.png");
	images[1][5] = new Image("img/move/left/5.png");

	images[2][0] = new Image("img/move/up/0.png");
	images[2][1] = new Image("img/move/up/1.png");
	images[2][2] = new Image("img/move/up/2.png");
	images[2][3] = new Image("img/move/up/3.png");
	images[2][4] = new Image("img/move/up/4.png");
	images[2][5] = new Image("img/move/up/5.png");

	images[3][0] = new Image("img/move/right/0.png");
	images[3][1] = new Image("img/move/right/1.png");
	images[3][2] = new Image("img/move/right/2.png");
	images[3][3] = new Image("img/move/right/3.png");
	images[3][4] = new Image("img/move/right/4.png");
	images[3][5] = new Image("img/move/right/5.png");
}

void Person::Draw(int x) {
	if (x == -1) {
		SDL_BlitSurface(images[0][0]->img, nullptr, surface, midle);
		return;
	}
	if (x != cur_type) {
		cur_time = 0;
		//if (x<2)
		cur_type = x;
	}
	if (++cur_time == time) {
		cur_time = 0;
		point = (point + 1) % 6;
	}
	SDL_BlitSurface(images[cur_type][point]->img, nullptr, surface, midle);
}

Person::~Person() {
	delete midle;
	delete img;
}