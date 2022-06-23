#pragma once
#include "Cell.h"
#include "Array.h"
namespace Game {
	class Pole {
	public:
		int size;
		Array<Array<Cell*>> cells;
		Pole(int n, Fl_Window& w, double size_ = 1);
		static void Draw_pole(Array<Array<int>>& m);
		~Pole();
	};
}
