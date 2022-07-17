#include <iostream>
#include "Window.h"

Window* Window::me = nullptr;
Start* Start::me = nullptr;
int main() {
	Fl_Window window(550, 650, "Sapper");
	Window win(window);
	window.show();

	return Fl::run();
}