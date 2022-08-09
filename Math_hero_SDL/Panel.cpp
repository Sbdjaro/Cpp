#include "Panel.h"
#include "Window.h"

Panel::Panel(SDL_Window* w, SDL_Surface* s) : win(w), surface(s) {
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
	img_sign.push_back(new Image("img/number/eq.png"));  // =,+,-,_
	img_sign.push_back(new Image("img/number/plus.png"));
	img_sign.push_back(new Image("img/number/minus.png"));
	img_sign.push_back(new Image("img/number/_.png"));
	rect_task.push_back(new SDL_Rect{ 510,455,20,20 });
	rect_task.push_back(new SDL_Rect{ 530,455,20,20 });
	rect_task.push_back(new SDL_Rect{ 550,455,20,20 });
	rect_task.push_back(new SDL_Rect{ 570,455,20,20 });
	rect_answer.push_back(new SDL_Rect{ 520,490,20,20 });
	rect_answer.push_back(new SDL_Rect{ 540,490,20,20 });
	rect_figures = new SDL_Rect{ 0,0,20,20 };
	score = new Score(w,s,&figures);
	health = new Health(w, s, &figures);
	Generate();
}

void Panel::Draw() {
	SDL_BlitSurface(figures[task1]->img, rect_figures, surface, rect_task[0]);
	if (plus)
		SDL_BlitSurface(img_sign[1]->img, rect_figures, surface, rect_task[1]);
	else 
		SDL_BlitSurface(img_sign[2]->img, rect_figures, surface, rect_task[1]);
	SDL_BlitSurface(figures[task2]->img, rect_figures, surface, rect_task[2]);
	SDL_BlitSurface(img_sign[0]->img, rect_figures, surface, rect_task[3]);
	if (cur_sign) {
		SDL_BlitSurface(img_sign[2]->img, rect_figures, surface, rect_answer[0]);
		SDL_BlitSurface(figures[current%10]->img, rect_figures, surface, rect_answer[1]);
	}
	else if (current!=0) {
		SDL_BlitSurface(figures[current % 10]->img, rect_figures, surface, rect_answer[1]);
		if (current / 10!=0)
			SDL_BlitSurface(figures[current/10]->img, rect_figures, surface, rect_answer[0]);
		else
			SDL_BlitSurface(img_sign[3]->img, rect_figures, surface, rect_answer[0]);
	}
	else {
		SDL_BlitSurface(img_sign[3]->img, rect_figures, surface, rect_answer[0]);
		SDL_BlitSurface(img_sign[3]->img, rect_figures, surface, rect_answer[1]);
	}
	score->Draw();
	health->Draw();
}

void Panel::Add(int c) {
	if (current > 9) {
		cur_sign = false;
		current %= 10;
	}
	current *= 10;
	current += c;
}

void Panel::Minus() {
	if (current == 0)
		cur_sign = true;
}
void Panel::Generate() {
	cur_sign = false;
	task1 = rand() % 10;
	task2 = rand() % 10;
	plus = rand() % 2 == 1;
	task = plus ? task1 + task2 : task1 - task2;
}

void Panel::Check() {
	if (task == (cur_sign? -current:current)) {
		Generate();	
		Window::me->pole->Shoot_aim();
	}
	cur_sign = false;
	current = 0;
}








Panel::~Panel() {
	for (int i = 0; i < (int)figures.size(); i++)
		delete figures[i];
	for (int i = 0; i < (int)rect_task.size(); i++)
		delete rect_task[i];
	for (int i = 0; i < (int)rect_answer.size(); i++)
		delete rect_answer[i];
	delete rect_figures;
	delete score;
	delete health;
}

Score::Score(SDL_Window* w,SDL_Surface* s, vector<Image*>* i): win(w), surface(s),figures(i){
	img_score = new Image("img/score.png");
	rect_score = new SDL_Rect{ 750,50,150,50 };
	rect_figures.push_back(new SDL_Rect{ 920,70,20,20 });
	rect_figures.push_back(new SDL_Rect{ 940,70,20,20 });
	rect_figures.push_back(new SDL_Rect{ 960,70,20,20 });
	rect_figures.push_back(new SDL_Rect{ 980,70,20,20 });
}

Score::~Score(){
	delete img_score;
	delete rect_score;
	for (int i = 0; i < (int)rect_figures.size(); i++)
		delete rect_figures[i];

}

void Score::Draw(){
	SDL_BlitSurface(img_score->img, nullptr, surface, rect_score);
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
	if (score == 0) {
		SDL_BlitSurface((*figures)[0]->img, nullptr, surface, rect_figures[0]);
		return;
	}
	int i = 0;
	while (tmp != 0) {
		SDL_BlitSurface((*figures)[tmp%10]->img, nullptr, surface, rect_figures[start-i]);
		i++;
		tmp /= 10;
	}
}

void Score::Add(){
	score++;
}


Health::Health(SDL_Window* w, SDL_Surface* s, vector<Image*>* i) : win(w), surface(s), figures(i) {
	img_health = new Image("img/health.png");
	rect_health = new SDL_Rect{ 50,50,150,50 };
	rect_figures.push_back(new SDL_Rect{ 200,70,20,20 });
	rect_figures.push_back(new SDL_Rect{ 220,70,20,20 });
	rect_figures.push_back(new SDL_Rect{ 240,70,20,20 });
}

Health::~Health() {
	delete img_health;
	delete rect_health;
	for (int i = 0; i < (int)rect_figures.size(); i++)
		delete rect_figures[i];
}

void Health::Draw() {
	SDL_BlitSurface(img_health->img, nullptr, surface, rect_health);
	int tmp = health;
	int i = 0;
	while (tmp != 0) {
		SDL_BlitSurface((*figures)[tmp % 10]->img, nullptr, surface, rect_figures[2 - i]);
		i++;
		tmp /= 10;
	}
}

void Health::Add(int x) {
	health = min(100, health + x);
}

void Health::Sub() {
	health = max(0, health - 10);
	if (health == 0)
		Window::me->End_game();
}