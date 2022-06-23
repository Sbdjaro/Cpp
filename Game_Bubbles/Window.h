#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "Special_buttons.h"
#include "Pole.h"
#include "Next_button.h"
#include "Err_Window.h"
#include "Saves.h"

namespace Game {
	class Window {
	public:
		Err_Window* err;
		Fl_Window* win;
		Special_buttons buttons;
		Save save;
		Next_button next;
		static Window* me;
		Pole pole;
		Window(Fl_Window& window, double size, int num);
		void Color_all();
		~Window();
	};

	Window* Get_me();
}
