#include "Window.h"


namespace Game {

	Window::Window(Fl_Window& window, double size, int num) : buttons(window, size), pole(num, window, size), win(&window), next(num, window, size), save(window, size, num) {
		err = new Err_Window(1);

		me = this;
		Color_all();
	}

	Window* Get_me() {
		return Window::me;
	}

	Window::~Window() {
		delete err;
	}

	void Window::Color_all() {
		for (int i = 0; i < pole.cells.size(); i++) {
			for (int j = 0; j < pole.cells[i].size(); j++) {
				pole.cells[i][j]->Color();
			}
		}
	}
}
