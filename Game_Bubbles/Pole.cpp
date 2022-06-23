#include "Pole.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "Window.h"
namespace Game {
	Pole::Pole(int n, Fl_Window& w, double size_) : size(n) {
		w.begin();
		for (int i = 0; i < n; i++) {
			Array<Cell*> tmp;
			for (int j = 0; j < n; j++)
				tmp.push_back(new Cell(i, j, size_ * 500 / n, size_));
			cells.push_back(tmp);
		}
		w.end();
	}

	void Pole::Draw_pole(Array<Array<int>>& m) {
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Get_me()->win->begin();
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m.size(); j++) {
				switch (m[i][j]) {
				case 0:
					Cell::Dublicate_cell(&tmp[i][j]);
					break;

				case 1:
					Cell::Dublicate_bubble(&tmp[i][j]);
					break;
				case 2:
					Cell::Dublicate_ball(&tmp[i][j]);
					break;
				}
			}
		}
		Get_me()->Color_all();
		Get_me()->win->redraw();
		Get_me()->win->end();

	}
	Pole::~Pole() {
		for (int i = 0; i < cells.size(); i++)
			for (int j = 0; j < cells[i].size(); j++) {
				delete cells[i][j];
			}
	}
}
