#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "Cell.h"
#include "Array.h"

namespace Game {
	class Next_button {
		Fl_Button* button;
		Array<Array<int>> matrix;


		static void Click(Fl_Widget* pb, void* t);

		static int Calc_obj(int x, int y);
		static void Explose_help(int x, int y, int dir);
		static void Explose(int x, int y);
		static void Transport_help(int x, int y, int, int, int);
		static void Transport(int x, int y);
		static void Pos_matrix(Array<Array<int>>&, int x);
		static void Stop_walls(int x, int y);
		static void find_dir(int x, int y);
	public:
		Next_button(int len, Fl_Window& w, double size);
		~Next_button();
	};
}
