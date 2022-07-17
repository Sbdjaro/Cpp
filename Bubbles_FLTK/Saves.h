#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "Array.h"
namespace Game {
	class Save {
		Array<Array<int>> saves[3];
		Fl_Button* rand_button;
		Fl_Button* save_button[3];
		Fl_Button* load_button[3];
		Fl_Button* clear_button;
		static Save* me;

		static void Load_call(Fl_Widget* pb, void* t);
		static void Save_call(Fl_Widget* pb, void* t);
		static void Random_call(Fl_Widget* pb, void* t);
		static void Clear_call(Fl_Widget* pb, void* t);
	public:
		Save(Fl_Window& w, int size, int len);
		~Save();

	};
}