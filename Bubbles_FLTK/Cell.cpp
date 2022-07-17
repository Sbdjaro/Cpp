#include "Cell.h"
#include "Window.h"
namespace Game {
	void raise_err(std::string s) {
		Get_me()->err->Show(s);
		return;
	}
	Cell::Cell(const int& x, const int& y, const int& size, double start) :pos_x(x), pos_y(y), size(size), start(start) {
		button = new Fl_Button(100 * start + x * size, y * size, size, size, "");
		button->callback(Click, nullptr);
	}

	Cell::Cell(const Cell& x) : pos_x(x.pos_x), pos_y(x.pos_y), size(x.size), start(x.start) {
		button = new Fl_Button(100 * start + pos_x * size, pos_y * size, size, size, "");
		button->callback(Click, nullptr);
	}
	Cell::~Cell() {
		delete button;
	}
	void Cell::Click(Fl_Widget* pb, void*) {
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Fl_Color fl;
		bool t = true;
		for (int i = 0; i < tmp.size() && t; i++) {
			for (int j = 0; j < tmp[i].size() && t; j++) {
				if (tmp[i][j]->button->contains(pb)) {
					Cell* tp;
					Get_me()->win->begin();
					switch (Get_me()->buttons.type) {
					case 0:
						if (tmp[i][j]->Info() != 0) {
							//raise_err();
							std::cout << "Bad Cell< already bucy\n";
							return;
						}
						tp = tmp[i][j];
						tmp[i][j] = new Ball(*tp);
						delete tp;
						break;
					case 1:
						if (tmp[i][j]->Info() != 0) {
							raise_err("Bad Cell< already bucy");
							std::cout << "Bad Cell< already bucy\n";
							return;
						}
						tp = tmp[i][j];
						tmp[i][j] = new Bubble(*tp);
						delete tp;
						break;
					case 2:
						if (tmp[i][j]->Info() != 2) {
							raise_err("It is not a ball");
							std::cout << "It is not ball\n";
							return;
						}
						tp = tmp[i][j];
						tmp[i][j] = new Cell(*tp);
						delete tp;
						break;
					case 3:
						if (tmp[i][j]->Info() != 1) {
							raise_err("It is not a bubble");
							std::cout << "It is not bubble\n";
							return;
						}
						tp = tmp[i][j];
						tmp[i][j] = new Cell(*tp);
						delete tp;
						break;
					}
					tmp[i][j]->Color();
					Get_me()->win->end();
					Get_me()->win->redraw();
					t = false;
				}

			}
		}
	}

	int Cell::Rand_dir() {
		int x = rand() % 8;
		x -= 4;
		if (x == 0)
			x = 4;
		return x;
	}

	void Cell::Dublicate_cell(Cell** x) {
		Cell* tp = *x;
		*x = new Cell(*tp);
		(*x)->dir = 0;
		delete tp;
	}
	void Cell::Dublicate_bubble(Cell** x) {
		Cell* tp = *x;
		*x = new Bubble(*tp);
		(*x)->dir = 0;
		delete tp;
	}
	void Cell::Dublicate_ball(Cell** x) {
		Cell* tp = *x;
		*x = new Ball(*tp);
		(*x)->dir = 0;
		delete tp;
	}


	Round::Round(const Cell& x) : Cell(x) {

	}

	Bubble::Bubble(const Cell& x) : Round(x) {

	}
	Ball::Ball(const Cell& x) : Round(x) {

	}
	void Bubble::Color() {
		button->color(fl_rgb_color(0, 0, 255));
	}
	void Cell::Color() {
		button->color(fl_rgb_color(0, 255, 255));
	}
	void Ball::Color() {
		button->color(fl_rgb_color(255, 0, 0));
	}

	int Cell::Info() { return 0; }
	int Round::Info() { return 0; }
	int Bubble::Info() { return 1; }
	int Ball::Info() { return 2; }

	void Cell::Change_dir() { dir = 0; }
	void Round::Change_dir() { dir = 0; }
	void Bubble::Change_dir() {
		dir = Rand_dir();
	}
	void Ball::Change_dir() {
		dir = Rand_dir();
	}
}
