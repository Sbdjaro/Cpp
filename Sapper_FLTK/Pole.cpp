#pragma once
#include "Pole.h"
#include "Window.h"

Pole::Pole(int size, int bomb):bomb(bomb),opened(0),size(size) {
	bg = new Fl_Box(0, 0, 550, 550);
	bg->color(fl_rgb_color(150, 150, 150));
	bg->activate();
	bg->box(FL_UP_BOX);
	vector<vector<Cell*>> res;
	vector<Cell*> tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tmp.push_back(new Cell(i * 500 / size+25, j * 500 / size+25, 500 / size));
		}
		res.push_back(tmp);
		tmp.clear();
	}
	cells = res;
	vector<vector<int>> h(cells.size(), vector<int>(cells.size(), 0));
	open = h;
	Window::me->menu->Text_int(size*size, bomb);
}

void Pole::Generate(int x1, int y1) {
	vector<vector<int>> h(cells.size(), vector<int>(cells.size(), 0));
	int x, y;
	for (int i = 0; i < bomb; i++) {
		x = std::rand() % cells.size();
		y = std::rand() % cells.size();
		if (abs(x - x1) <= 1 && abs(y - y1) <= 1)
		{
			i--;
			continue;
		}
		if (h[x][y] != -1)
			h[x][y] = -1;
		else
			i--;
	}
	table = h;
	Calc();
	Draw();
}

void Pole::Calc() {
	int k = 0;
	vector<vector<int>> h(cells.size(), vector<int>(cells.size(), 0));
	for (int i = 0; i < cells.size(); i++)
		for (int j = 0; j < cells.size(); j++) {
			if (table[i][j] == -1)
				continue;
			k = 0;
			if (i > 0) {
				if (j > 0)
					if (table[i - 1][j - 1] == -1)
						k += 1;
				if (j < cells.size()-1)
					if (table[i - 1][j + 1] == -1)
						k += 1;
				if (table[i - 1][j] == -1)
					k += 1;
			}
			if (i < cells.size()-1) {
				if (j > 0)
					if (table[i + 1][j - 1] == -1)
						k += 1;
				if (j < cells.size() - 1)
					if (table[i + 1][j + 1] == -1)
						k += 1;
				if (table[i + 1][j] == -1)
					k += 1;
			}
			if (j > 0)
				if (table[i][j - 1] == -1)
					k += 1;
			if (j < cells.size() - 1)
				if (table[i][j + 1] == -1)
					k += 1;
			h[i][j] = k;
		}
	full = h;
	
}

void Pole::Draw() {
	for (int i = 0; i < cells.size(); i++)
		for (int j = 0; j < cells.size(); j++) {
			if (open[i][j] == 0) {
				cells[i][j]->Set_zero();
				continue;
			}
			if (open[i][j] == -1)
			cells[i][j]->Set_flag();
			else if (table[i][j] == -2)
				cells[i][j]->Set_Explos();
			else if (table[i][j] ==-1)
				cells[i][j]->Set_bomb();
			else
				cells[i][j]->Set_num(full[i][j]);
		}
	if (active)
	Window::me->menu->Text_int(size*size-opened, bomb-flag);
	Window::me->win->redraw();
}

vector<int> Pole::What_Button(Fl_Widget* pb) {
	vector<int> res;
	for (int i = 0; i < cells.size(); i++)
		for (int j = 0; j < cells.size(); j++) {
			if (cells[i][j]->button->contains(pb)) {
				res.push_back(i);
				res.push_back(j);
			 }
		}
	return res;
}

void Pole::Update(vector<int> click) {
	if (table[click[0]][click[1]] == -1) {
		Game_Over();
		return;
	}
	int size = cells.size();
	stack<vector<int>> stak;
	vector<int> tmp(2), tmp2(2);
	tmp = click;
	stak.push(tmp);
	while (!stak.empty()) {
		tmp = stak.top();
		stak.pop();
		if (full[tmp[0]][tmp[1]] == 0 && open[tmp[0]][tmp[1]] != 1) {
			if (tmp[0] > 0) {
				tmp2[0] = tmp[0] - 1;
				tmp2[1] = tmp[1];
				stak.push(tmp2);
			}
			if (tmp[1] > 0) {
				tmp2[0] = tmp[0];
				tmp2[1] = tmp[1] - 1;
				stak.push(tmp2);
			}
			if (tmp[0] < size - 1) {
				tmp2[0] = tmp[0] + 1;
				tmp2[1] = tmp[1];
				stak.push(tmp2);
			}
			if (tmp[1] < size - 1) {
				tmp2[0] = tmp[0];
				tmp2[1] = tmp[1] + 1;
				stak.push(tmp2);
			}
			if (tmp[0] > 0 && tmp[1] > 0) {
				tmp2[0] = tmp[0] - 1;
				tmp2[1] = tmp[1] - 1;
				stak.push(tmp2);
			}
			if (tmp[0] > 0 && tmp[1] < size - 1) {
				tmp2[0] = tmp[0] - 1;
				tmp2[1] = tmp[1] + 1;
				stak.push(tmp2);
			}
			if (tmp[0] < size - 1 && tmp[1] < size - 1) {
				tmp2[0] = tmp[0] + 1;
				tmp2[1] = tmp[1] + 1;
				stak.push(tmp2);
			}
			if (tmp[0] < size - 1 && tmp[1]>0) {
				tmp2[0] = tmp[0] + 1;
				tmp2[1] = tmp[1] - 1;
				stak.push(tmp2);
			}
			
		}
		if (open[tmp[0]][tmp[1]]==0) opened += 1;
		open[tmp[0]][tmp[1]] = 1;
	}
	Draw();
	if (-opened + size * size == bomb) {
		Game_Win();
	}
}

void Pole::Flag(vector<int> click) {

	if (open[click[0]][click[1]] == -1) {

		open[click[0]][click[1]] = 0;
		flag--;
	}
	else if (open[click[0]][click[1]] == 1)
		return;
	else {
		open[click[0]][click[1]] = -1;
		flag++;

	}

		Draw();
	
}

void Pole::Game_Over() {
	for (int i = 0; i < cells.size(); i++)
		for (int j = 0; j < cells.size(); j++) {
			if (table[i][j] == -1) {
				table[i][j] = -2;
				open[i][j] = 1;
			}
		}
	active = false;
	Window::me->menu->Text("You Lose :(");
	Draw();

}

void Pole::Game_Win() {
	for (int i = 0; i < cells.size(); i++)
		for (int j = 0; j < cells.size(); j++) {
			if (table[i][j] == -1) {
				full[i][j] = 0;
				open[i][j] = 1;
			}
		}
	active = false;
	Window::me->menu->Text("You Win!");
	Draw();

}

void Pole::Restart() {
	for (int i = 0; i < cells.size(); i++)
		for (int j = 0; j < cells.size(); j++) {
			open[i][j] = 0;
		}
	start = true;
	opened = 0;
	active = true;
	flag = 0;
	Draw();
}

Pole::~Pole() {
	for (int i = 0; i < cells.size(); i++)
		for (int j = 0; j < cells.size(); j++)
			delete cells[i][j];
	delete bg;

}