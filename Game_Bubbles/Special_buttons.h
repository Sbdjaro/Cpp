#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <string>
namespace Game {
	class Special_buttons {

		Fl_Button* others[4];
		static Fl_Widget* active;
		Fl_Color Color_std = fl_rgb_color(255, 255, 255);
		std::string NAME[4] = { "Add a ball","Add a bubble","Take a ball","Burst the\nbubble" };

		static void Click(Fl_Widget* pb, void* t);
		void Update_local();
		void Deselect_all();
		void Select(int i);
	public:
		int type = 0;
		Special_buttons(Fl_Window& w, double size);
		~Special_buttons();
	};
}
