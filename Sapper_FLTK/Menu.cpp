#pragma once
#include "Menu.h"
#include "Window.h"
Menu::Menu() {
	text = new Fl_Box(350,520,100,80,"Chose level");
	restart = new Fl_Button(270,580,100,50);
	restart->copy_label("Restart");
	restart->color(fl_rgb_color(255, 255, 255));
	restart->color2(fl_rgb_color(255, 255, 255));
	restart->callback(Click_restart,nullptr);
	change = new Fl_Button(430, 580, 100, 50);
	change->callback(Click_change, nullptr);
	change->copy_label("Change level");
	change->color(fl_rgb_color(255, 255, 255));
	change->color2(fl_rgb_color(255, 255, 255));
}

void Menu::Click_restart(Fl_Widget* pb, void*) {
	if (Window::me->pole == NULL)
		return;
	std::cout << "HELLLLLLL";
	Window::me->pole->Restart();
	
}
void Menu::Click_change(Fl_Widget* pb, void*) {
	if (Window::me->pole == NULL)
		return;
	std::cout << "HELLLLLLL";
	Start::me->Open();
	delete Window::me->pole;
	Window::me->pole = nullptr;
	Window::me->win->redraw();
}
void Menu::Text(std::string s) {
	text->copy_label(s.c_str());
}
void Menu::Text_int(int x, int y) {
	std::string s = "Closed cells: ";
	s += std::to_string(x);
	s += ", Bombs: ";
	s += std::to_string(y);
	text->copy_label(s.c_str());
}
Menu::~Menu() {
	delete text;
	delete restart;
	delete change;
}