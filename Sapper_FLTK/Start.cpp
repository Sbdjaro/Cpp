#include "Start.h"
#include "Window.h"
Start::Start() {
	
	bg = new Fl_Box(175, 100, 200, 400);
	bg->color(fl_rgb_color(255, 255, 255));
	bg->color2(fl_rgb_color(100, 100, 100));
	bg->box(FL_UP_BOX);
	text.push_back(new Fl_Box(175+75, 50, 50, 200, "Size"));
	text.push_back(new Fl_Box(175+75, 185, 50, 200, "Difficulty"));
	start = new Fl_Button(50+175, 320+100, 100, 60, "Start");
	start->callback(Click,nullptr);
	start->color(fl_rgb_color(0, 255, 0));
	for (int i = 0; i < 3; i++) {
		size.push_back(new Fl_Button(32+i*50 +175, 80+100, 40, 40));
		size.back()->callback(Click_size);
		bomb.push_back(new Fl_Button(32+i*50+175, 220+100, 40, 40));
		bomb.back()->callback(Click_bomb);
	}
	size[0]->copy_label("8");
	size[1]->copy_label("10");
	size[2]->copy_label("16");
	bomb[0]->copy_label("Easy");
	bomb[1]->copy_label("Med");
	bomb[2]->copy_label("Hard");
	size[0]->color(fl_rgb_color(255, 255, 255));
	bomb[0]->color(fl_rgb_color(255, 255, 255));
	size[1]->color(fl_rgb_color(255,255, 0));
	bomb[1]->color(fl_rgb_color(255,255, 0));
	size[2]->color(fl_rgb_color(255, 255, 255));
	bomb[2]->color(fl_rgb_color(255, 255, 255));
	me = this;
}

void Start::Click(Fl_Widget* pb, void*) {
	Window::me->Start_Game(Start::me->size_int, Start::me->bomb_int* Start::me->size_int);
	Window::me->start->Hide();
}

void Start::Click_size(Fl_Widget* pb, void*) {
	int i = 0;
	for (; i < 3; i++)
		if (Window::me->start->size[i]->contains(pb))
			break;
	switch (i) {
	case 0: Window::me->start->size_int=8;
		break;
	case 1:
		Window::me->start->size_int = 10;
			break;
	case 2:
		Window::me->start->size_int = 16;
	}
	Window::me->start->Draw1();
}

void Start::Click_bomb(Fl_Widget* pb, void*) {
	int i = 0;
	for (; i < 3; i++)
		if (Window::me->start->bomb[i]->contains(pb))
			break;
	Window::me->start->bomb_int = i;
	if (i==0)
		Window::me->start->bomb_int = 0.5;
	if (i == 2)
		Window::me->start->bomb_int = 1.5;
	Window::me->start->Draw2();
}


void Start::Open() {
	bg->show();
	start->show();
	for (int i = 0; i < 3; i++) {
		bomb[i]->show();
		size[i]->show();
	}
}

void Start::Hide() {
	bg->hide();
	start->hide();
	for (int i = 0; i < 3; i++) {
		bomb[i]->hide();
		size[i]->hide();
	}
}

void Start::Draw1() {
	size[0]->color(fl_rgb_color(255, 255, 255));
	size[1]->color(fl_rgb_color(255, 255, 255));
	size[2]->color(fl_rgb_color(255, 255, 255));
	if (size_int == 8) {
		size[0]->color(fl_rgb_color(255, 255, 0));
	}
	else if (size_int == 10) {
		size[1]->color(fl_rgb_color(255, 255, 0));
	}
	else {
		size[2]->color(fl_rgb_color(255, 255, 0));
	}
	Window::me->win->redraw();
}

void Start::Draw2() {
	bomb[0]->color(fl_rgb_color(255, 255, 255));
	bomb[1]->color(fl_rgb_color(255, 255, 255));
	bomb[2]->color(fl_rgb_color(255, 255, 255));
	if (bomb_int == 0.5) {
		bomb[0]->color(fl_rgb_color(255, 255, 0));
	}
	else if (bomb_int == 1) {
		bomb[1]->color(fl_rgb_color(255, 255, 0));
	}
	else {
		bomb[2]->color(fl_rgb_color(255, 255, 0));
	}
	Window::me->win->redraw();
}

Start::~Start() {
	delete bg;
	delete start;
	for (int i = 0; i < 3; i++) {
		delete bomb[i];
		delete size[i];
	}
	delete text[0];
	delete text[1];
}