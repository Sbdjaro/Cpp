#include "Game_over.h"

Game_over::Game_over(SDL_Window* w, SDL_Surface* s):win(w),surface(s),score(0),time(0) {
	figures.push_back(new Image("img/number/0.png"));
	figures.push_back(new Image("img/number/1.png"));
	figures.push_back(new Image("img/number/2.png"));
	figures.push_back(new Image("img/number/3.png"));
	figures.push_back(new Image("img/number/4.png"));
	figures.push_back(new Image("img/number/5.png"));
	figures.push_back(new Image("img/number/6.png"));
	figures.push_back(new Image("img/number/7.png"));
	figures.push_back(new Image("img/number/8.png"));
	figures.push_back(new Image("img/number/9.png"));

	rect_score.push_back(new SDL_Rect{ 510,295,20,20 });
	rect_score.push_back(new SDL_Rect{ 530,295,20,20 });
	rect_score.push_back(new SDL_Rect{ 550,295,20,20 });
	rect_score.push_back(new SDL_Rect{ 570,295,20,20 });

	rect_time.push_back(new SDL_Rect{ 510,530,20,20 });
	rect_time.push_back(new SDL_Rect{ 530,530,20,20 });
	rect_time.push_back(new SDL_Rect{ 550,530,20,20 });
	rect_time.push_back(new SDL_Rect{ 570,530,20,20 });

	img_end = SDL_LoadBMP("img/white.bmp");
}

void Game_over::Set(int x, int y){
	score = x;
	time = y;
}

void Game_over::Draw(){
	SDL_BlitSurface(img_end, nullptr, surface, nullptr);
	int start;
	if (score < 10)
		start = 0;
	else if (score < 100)
		start = 1;
	else if (score < 1000)
		start = 2;
	else
		start = 3;
	int tmp = score;
	int i;
	if (score == 0) {
		SDL_BlitSurface(figures[0]->img, nullptr, surface, rect_score[0]);
	}
	else {
		i = 0;
		while (tmp != 0) {
			SDL_BlitSurface(figures[tmp % 10]->img, nullptr, surface, rect_score[start - i]);
			i++;
			tmp /= 10;
		}
	}

	if (time < 10)
		start = 0;
	else if (time < 100)
		start = 1;
	else if (time < 1000)
		start = 2;
	else
		start = 3;
	tmp = time;
	if (time == 0) {
		SDL_BlitSurface(figures[0]->img, nullptr, surface, rect_time[0]);
	}
	else {
		i = 0;
		while (tmp != 0) {
			SDL_BlitSurface(figures[tmp % 10]->img, nullptr, surface, rect_time[start - i]);
			i++;
			tmp /= 10;
		}
	}
	SDL_UpdateWindowSurface(win);

}

Game_over::~Game_over(){
	for (int i = 0; i < (int)figures.size(); i++)
		delete figures[i];
	for (int i = 0; i < (int)rect_score.size(); i++)
		delete rect_score[i];
	for (int i = 0; i < (int)rect_time.size(); i++)
		delete rect_time[i];

	SDL_FreeSurface(img_end);
}
