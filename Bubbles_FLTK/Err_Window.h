#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <string>
namespace Game {
	class Err_Window {

		Fl_Window* window;
		Fl_Button* button;
		Fl_Box* text;
		std::string str;
		static Err_Window* me;
	public:
		Err_Window(int mid);
		static void Show(std::string s);
		static void Hide_call(Fl_Widget* pb, void*);
		~Err_Window();
	};
}
