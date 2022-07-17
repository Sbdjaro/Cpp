#pragma once
#include <Fl/Fl.h>
#include <Fl/Fl_Button.H>

class Flag {

	bool active = false;
	Fl_Button* button_on;
	Fl_Button* button_off;
	static void Click_on(Fl_Widget* pb, void*);
	static void Click_off(Fl_Widget* pb, void*);
public:
	Flag();
	bool Info();
	~Flag();
};