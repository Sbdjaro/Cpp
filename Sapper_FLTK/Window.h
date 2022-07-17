#pragma once
#include "Pole.h"
#include "Flag.h"
#include "Menu.h"
#include "Start.h"

class Window {
public:
	Window(Fl_Window& window);
	Menu* menu;
	Pole* pole;
	Flag* flag;
	Fl_Window* win;
	Start* start;
	static Window* me;
	void Start_Game(int,int);
	~Window();
};
