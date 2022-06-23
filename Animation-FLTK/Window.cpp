#include "Window.h"


namespace Game {
	void Window::fuu(void* t) {
		Fl::repeat_timeout(0.1, fuu);
		me->image->Draw(0, 0);
	}
	Window::Window(Fl_Window *window, const std::string &s) :  win(window) {
		if (s == "Forest")
			image = new Picture();
		Fl::add_timeout(0.1, fuu);
		me = this;
	}

	Window* Get_me() {
		return Window::me;
	}

	Window::~Window() {
		delete image;
	}

}
