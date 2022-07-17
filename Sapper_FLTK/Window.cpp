#pragma once
#include "Window.h"

Window::Window(Fl_Window& window): win(&window){
	me = this;
	menu = new Menu();
	flag = new Flag();
	start = new Start();
	
}

void Window::Start_Game(int x, int y) {
	win->begin();
	std::cout << x<< y;
	pole = new Pole(x, y);
	win->end();
	win->redraw();
}

Window::~Window() {
	delete pole; 
	delete flag;
	delete menu;
	delete start;
}