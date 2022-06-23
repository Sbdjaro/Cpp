#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Window.h"
using namespace Game;
int x = 0;
Window* Window::me = nullptr;
Fl_Widget* Special_buttons::active = nullptr;
Err_Window* Err_Window::me = nullptr;
Save* Save::me = nullptr;
int main() {
	double s,n;
	std::cout << "Side, please: ";
	std::cin >> s;
	srand(s);
	std::cout << "Size, please: ";
	std::cin >> n;
	std::cout << "Number of cells, please: ";
	std::cin >> s;
	Fl_Window window(700*n, 500*n, "Window title");
	window.begin();
	Window P(window,n,s);
	window.end();
	window.show();
	return Fl::run();


}


