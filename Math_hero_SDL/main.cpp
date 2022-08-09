#include <iostream>
#include <SDL.h>
#include "Window.h"
#include <math.h>
#undef main
using namespace std;
Window* Window::me = nullptr;


int main() {
	srand((long)time(nullptr));
	Window win;
	win.Pro();
	return 0;
}