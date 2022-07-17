#pragma once
#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include "iostream"
class Cell {
public:
	Fl_Button* button;
	Cell(int x, int y, int size);
	static void Click(Fl_Widget* pb, void*);
	
	void Set_num(int x);
	void Set_zero();
	void Set_flag();
	void Set_bomb();
	void Set_Explos();
	~Cell();
};