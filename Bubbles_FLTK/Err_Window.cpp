#include "Err_Window.h"
namespace Game {
	void Err_Window::Show(std::string s) {
		me->text->copy_label(s.c_str());
		me->window->show();
		return;
	}

	Err_Window::Err_Window(int mid) {
		str = "";
		window = new Fl_Window(200, 100, "Error");
		window->begin();
		button = new Fl_Button(0, mid * 50, 200, 50, "OK");
		text = new Fl_Box(0, -50 + mid * 50, 200, 50, "!!!!");
		window->position(mid * 350, mid * 250);
		button->callback(Hide_call);
		window->end();
		me = this;
	}
	void Err_Window::Hide_call(Fl_Widget* pb, void*) {
		me->window->hide();
		return;
	}

	Err_Window::~Err_Window() {

		delete button;
		delete text;
		delete window;
	}
}