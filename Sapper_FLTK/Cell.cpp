#include "Cell.h"
#include "Window.h"
Cell::Cell(int x, int y, int size) {
	button = new Fl_Button(x, y, size, size);
	button->callback(Click,nullptr);
	button->color(fl_rgb_color(179, 179, 179));
}
void Cell::Click(Fl_Widget* pb, void*) {
	if (!Window::me->pole->active)
		return;
	vector<int> cord= Window::me->pole->What_Button(pb);
	if (Window::me->flag->Info()) {
		if (!Window::me->pole->start)
			Window::me->pole->Flag(cord);
	}
	else {
		if (Window::me->pole->start) {
			Window::me->pole->start = false;
			Window::me->pole->Generate(cord[0], cord[1]);
		}
		Window::me->pole->Update(cord);
	}
}

void Cell::Set_zero() {
	button->color(fl_rgb_color(179, 179, 179));
	button->copy_label("");
}
void Cell::Set_bomb() {
	button->copy_label("BOMB");
	button->color(fl_rgb_color(0, 255, 0));
}
void Cell::Set_num(int x) {
	char s =x+'0';
	string ss = ""; ss += s;
	if (ss == "0") ss = "";
	button->copy_label(ss.c_str());
	button->color(fl_rgb_color(255, 255, 255));
}
void Cell::Set_Explos() {
	button->color(fl_rgb_color(255, 0, 0));
}
void Cell::Set_flag() {
	button->color(fl_rgb_color(0, 255, 0));
	button->copy_label("Flag");
}

Cell::~Cell() {
	delete button;
}
