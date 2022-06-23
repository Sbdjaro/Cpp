#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Window.h"
//#include <FL/fl_draw.H>
//#include "All_Images.h"

using namespace Game;
Game::Window* Game::Window::me = nullptr;


int main() {


	Fl_Window window(700 , 500 , "GIF");
	window.begin();
	//Picture* su = new Picture();
	Game::Window P(&window, "Forest");

	window.end();
	window.show();
	return Fl::run();


}


