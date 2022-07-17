#pragma once
#include "Flag.h"
#include "Window.h"

Flag::Flag() {
	button_on = new Fl_Button(20+25, 520+50, 60, 60);
	button_on->callback(Click_on,nullptr);
	button_on->copy_label("Flag");
	button_on->color(fl_rgb_color(255, 255, 255));
	button_on->color2(fl_rgb_color(255, 255, 255));
	button_off = new Fl_Button(120+25, 520+50, 60, 60);
	button_off->copy_label("Open");
	button_off->callback(Click_off,nullptr);
	button_off->color(fl_rgb_color(0, 212, 155));
	button_off->color2(fl_rgb_color(0, 212, 155));
	button_off->resize(110+25, 510+50, 80, 80);
}
void Flag::Click_on(Fl_Widget* pb, void*) {
	Flag& t = *Window::me->flag;
	t.active = true;
	t.button_off->color(fl_rgb_color(255, 255, 255));
	t.button_off->color2(fl_rgb_color(255, 255, 255));
	t.button_off->resize(120+25, 520+50, 60, 60);
	t.button_on->color(fl_rgb_color(255, 0, 0));
	t.button_on->color2(fl_rgb_color(255, 0, 0));
	t.button_on->resize(10+25, 510+50, 80, 80);
	Window::me->win->redraw();
}

void Flag::Click_off(Fl_Widget* pb, void*) {
	Flag& t = *Window::me->flag;
	t.active = false;
	t.button_off->color(fl_rgb_color(0, 212, 155));
	t.button_off->color2(fl_rgb_color(0, 212, 155));
	t.button_off->resize(110+25, 510+50, 80, 80);
	t.button_on->color(fl_rgb_color(255, 255, 255));
	t.button_on->color2(fl_rgb_color(255, 255, 255));
	t.button_on->resize(20+25, 520+50, 60, 60);
	Window::me->win->redraw();
}

bool Flag::Info() {
	return active;
}

Flag::~Flag() {
	delete button_off;
	delete button_on;
}