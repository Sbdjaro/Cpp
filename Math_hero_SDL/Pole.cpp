#include "Pole.h"


Pole::Pole(SDL_Surface* s,SDL_Window* w):surface(s),map(70,vector<char>(70,1)),win(w),
one{ 32,vector<SDL_Rect*>(4,nullptr) }, two{70,vector<SDL_Rect*>(70,nullptr)}{
	for (int i = 20; i < 50; i++) {
		for (int j = 20; j < 50; j++) {
			map[i][j] = 0;
		}
	}
	
	for (int i = 20; i < 50; i++) {
		map[20][i] = 1;
		map[49][i] = 1;
		map[30][i] = 1;
		map[i][20] = 1;
		map[i][49] = 1;
	}
	map[30][30] = 0;

	x = 500;
	y = 500;
	box_img = SDL_LoadBMP("img/storage.bmp");
	pol_img = SDL_LoadBMP("img/pol.bmp");
	dark_img = SDL_LoadBMP("img/dark.bmp");
	rect = new SDL_Rect{ 0, 0, 50, 50 };
	midle = new SDL_Rect{ 475, 475, 525, 525 };
	inventory = new Inventory(w, s);
	person = new Person(w, s);
	balls = new All_balls(w, s);
	enemies = new All_Enemy(w, s);
	my_ball = new My_ball(w, s);
	panel = new Panel(w, s);
}

bool Pole::check_x(int x_) {
	
	x_ = (x_) / 50;
	int y_ = (y) / 50;

	if (map[x_+20][y_+20] == 0) {
		return true;
	}
	return false;
}
bool Pole::check_y(int y_) {
	int x_ = (x ) / 50;
	y_ = (y_) / 50;

	if (map[x_+20][y_+20] == 0) {
		return true;
	}
	return false;
}

bool Pole::check_xy(vector<int> v) {
	//cout << v[0] << " " << v[1] << "\n";
	try {
		if (map[(v[0]+1000) / 50][(v[1]+1000) / 50] == 0) {
			return true;
		}
		return false;
	}
	catch(...){
		return false;
	}
}

bool Pole::check_trace(vector<int> pose1, vector<int> pose2) {
	double len = sqrt((pose1[0] - pose2[0]) * (pose1[0] - pose2[0]) + (pose1[1] - pose2[1]) * (pose1[1] - pose2[1]));
	int interval = max(2,(int)len / 10);
	for (int i = 1; i < interval; i++) {
		
		if (!check_xy(vector<int>{pose1[0] + (-pose1[0] + pose2[0]) / interval * i, pose1[1] + (-pose1[1] + pose2[1]) / interval * i}))
			return false;
	}
	return true;
}

void Pole::Draw(int x_,int y_) {
	if (x_ * y_ != 0) {
		if (check_x(x_ * 6 + x))
		x += x_*2;
		if (check_y(y_ * 12 + y))
		y += y_*2;
	}
	else {
		if (check_x(x_ * 6 + x))
		x += x_ * 3;
		if (check_y(y_ * 12 + y))
		y += y_ * 3;
	}
	//cout << x << " " << y << "\n";
	/*
	for (int i = -1; i < 31; i++) {
		for (int j=0;j<4;j++)
			delete one[i+1][j];
		one[i+1][0] = new SDL_Rect{ i * 50 - x + 500,-50 - y + 500,i * 50 + 50 - x + 500,-50 + 50 - y + 500 };
		one[i+1][1] = new SDL_Rect{ -50 - x + 500,i * 50 - y + 500,-50 + 50 - x + 500,i * 50 + 50 - y + 500 };
		one[i+1][2] = new SDL_Rect{ i * 50 - x + 500,1500 - y + 500,i * 50 + 50 - x + 500,1500 + 50 - y + 500 };
		one[i+1][3] = new SDL_Rect{ 1500 - x + 500,i * 50 - y + 500,1500 + 50 - x + 500,i * 50 + 50 - y + 500 };
		SDL_BlitSurface(dark_img, rect, surface, one[i+1][0]);
		SDL_BlitSurface(dark_img, rect, surface, one[i+1][1]);
		SDL_BlitSurface(dark_img, rect, surface, one[i+1][2]);
		SDL_BlitSurface(dark_img, rect, surface, one[i+1][3]);
	}
	*/
	for (int i = 0; i < 70; i++)
		for (int j = 0; j < 70; j++) {
			delete two[i][j];
			two[i][j] = new SDL_Rect{ i * 50 - x + 500-1000,j * 50 - y + 500-1000,50,50 };
			if (map[i][j]==1)
				SDL_BlitSurface(box_img, rect, surface, two[i][j]);
			else
				SDL_BlitSurface(pol_img, rect, surface, two[i][j]);
		}
	if (x_==0&&y_==0)
		person->Draw(-1);
	if (y_ < 0)
		person->Draw(2);
	else if (y_ > 0)
		person->Draw(0);
	else if (x_ < 0)
		person->Draw(1);
	else if (x_ > 0)
		person->Draw(3);
	enemies->Draw();
	balls->Draw();
	my_ball->Draw();
	inventory->Draw();//*/
	panel->Draw();
	SDL_UpdateWindowSurface(win);

	
}

void Pole::Restart(){
	x = 750; y = 750;
	panel->Restart();
	inventory->Restart();
	balls->Restart();
	enemies->Restart();
	my_ball->Restart();
	person->Restart();
}

void Pole::Shoot(int x_, int y_) {
	vector<int> v = { x,y,x_,y_ };
	//cout << "Pole::Shoot\n";
	if (x_ * x_ + y_ * y_ == 0)
		return;
	my_ball->Shoot(v);
}
void Pole::Shoot_aim() {
	//cout << x << " " << y << "\n";
	vector<int> tmp = enemies->Get_near(x, y);
	//cout << tmp[0] << " " << tmp[1] << "\n";
	vector<int> v = { x,y,tmp[0]-x, tmp[1]-y };
	if (v[0] * v[0] + v[1] * v[1] == 0)
		return;
	my_ball->Shoot(v);
 }

Pole::~Pole() {
	for (int i = -1; i < 31; i++) 
		for (int j = 0; j < 4; j++)
			delete one[i + 1][j];
	for (int i = 0; i < 70; i++)
		for (int j = 0; j < 70; j++) 
			delete two[i][j];
	delete rect;
	delete person;
	delete inventory;
	delete balls;
	delete enemies;
	delete my_ball;
	delete panel;
	SDL_FreeSurface(box_img);
	SDL_FreeSurface(pol_img);
	SDL_FreeSurface(dark_img);
}