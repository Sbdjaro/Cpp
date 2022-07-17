#pragma once
#include <Fl/Fl.h>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <string>
class Menu {
	Fl_Box* text;
	Fl_Button* restart;
	Fl_Button* change;
	static void Click_restart(Fl_Widget* pb, void*);
	static void Click_change(Fl_Widget* pb, void*);
public:
	Menu();
	void Text(std::string s);
	void Text_int(int x, int y);
	~Menu();
};