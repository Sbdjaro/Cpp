#include "Shape.h"

namespace Game {
	Image::Image(std::vector<Shape*> other, Simple* form, std::vector<std::vector<int>> time, int sp) :sons(other), form(form),
		timepos(time), speed(sp) {
	}

	Image::Image(Simple* form, std::vector<std::vector<int>> time, int sp) : form(form), timepos(time), speed(sp) {
	}

	Image::Image() {
	}

	Image::~Image() {
		for (int i = 0; i < sons.size(); i++)
			delete sons[i];
		delete form;
	}

	void Image::Add_son(Shape* x) {
		sons.push_back(x);
	}
	void Image::Change_dir(std::vector<std::vector<int>> x, int sp) {
		timepos = x;
		if (sp != -1)
			speed = sp;
	}


	void Image::Draw(int x, int y) {
		form->draw(x + timepos[iter / speed][0], y + timepos[iter / speed][1]);

		for (int i = 0; i < sons.size(); i++) {
			sons[i]->Draw(x + timepos[iter / speed][0], y + timepos[iter / speed][1]);
		}
		iter += 1;
		iter = iter % (timepos.size() * speed);
	}

	void Image::Move(int x, int y) {
		form->move(x, y);
		for (int i = 0; i < sons.size(); i++) {
			sons[i]->Move(x, y);
		}
	}

	void Image::Resize(int t) {
		form->mult(t);
		for (int i = 0; i < sons.size(); i++) {
			sons[i]->Resize(t);
		}
	}
}