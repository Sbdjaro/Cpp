#pragma once
#include <vector>
#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>

class Start {
	Fl_Box* bg;
	std::vector<Fl_Box*> text;
	std::vector<Fl_Button*> size;
	std::vector<Fl_Button*> bomb;
	Fl_Button* start;
	int size_int=10;
	double bomb_int=1;
	static void Click(Fl_Widget* pb, void*);
	static void Click_size(Fl_Widget* pb, void*);
	static void Click_bomb(Fl_Widget* pb, void*);
public:
	static Start* me;
	Start();
	Fl_Window* win;
	void Open();
	void Hide();
	void Draw1();
	void Draw2();
	~Start();
};