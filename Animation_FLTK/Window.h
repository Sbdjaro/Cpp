#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "Picture.h"
#include <string>

namespace Game {
	class Window {


		Fl_Window* win;
		Shape* image;
		
		static void fuu(void* f);
	public:
		static Window* me;
		Window(Fl_Window* window, const std::string &s);
		~Window();
	};
	
	Window* Get_me();
}
