#include "Next_button.h"
#include "Window.h"

namespace Game {
	Next_button::Next_button(int len, Fl_Window& w, double size) {
		w.begin();
		button = new Fl_Button(0, 400 * size, 100 * size, 100 * size, "Next turn");
		button->labelsize(14 * size);
		button->color(fl_rgb_color(255, 255, 0));
		button->color2(fl_rgb_color(153, 153, 0));
		for (int i = 0; i < len; i++) {
			matrix.push_back(Array<int>(len));
		}
		button->callback(Click, nullptr);
		w.end();
	}
	Next_button::~Next_button() {
		delete button;
	}
	void Next_button::Pos_matrix(Array<Array<int>>& m, int x) {
		for (int i = 0; i < m.size(); i++)
			for (int j = 0; j < m[i].size(); j++)
				if (m[i][j] < 0)
					m[i][j] = x;

	}

	void Next_button::Stop_walls(int x, int y) {
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		if (x == 0) {
			if (tmp[x][y]->dir == 1 || tmp[x][y]->dir == 2 || tmp[x][y]->dir == 3) {
				if (tmp[x][y]->Info() == 1) {
					Cell::Dublicate_cell(&tmp[x][y]);
				}
				else {
					tmp[x][y]->dir *= -1;
					Get_me()->next.matrix[x][y] = -2;
				}
			}
		}
		if (y == 0) {
			if (tmp[x][y]->dir == 1 || tmp[x][y]->dir == -4 || tmp[x][y]->dir == -3) {
				if (tmp[x][y]->Info() == 1) {
					Cell::Dublicate_cell(&tmp[x][y]);
				}
				else {
					tmp[x][y]->dir *= -1;
					Get_me()->next.matrix[x][y] = -2;
				}
			}
		}
		if (y == tmp.size() - 1) {
			if (tmp[x][y]->dir == 3 || tmp[x][y]->dir == 4 || tmp[x][y]->dir == -1) {
				if (tmp[x][y]->Info() == 1) {
					Cell::Dublicate_cell(&tmp[x][y]);
				}
				else {
					tmp[x][y]->dir *= -1;
					Get_me()->next.matrix[x][y] = -2;
				}
			}
		}
		if (x == tmp.size() - 1) {
			if (tmp[x][y]->dir == -3 || tmp[x][y]->dir == -2 || tmp[x][y]->dir == -1) {
				if (tmp[x][y]->Info() == 1) {
					Cell::Dublicate_cell(&tmp[x][y]);
				}
				else {
					tmp[x][y]->dir *= -1;
					Get_me()->next.matrix[x][y] = -2;
				}
			}
		}
		if (x == 0 & y == 0) {
			if (tmp[x][y]->dir == 3 || tmp[x][y]->dir == -3) {
				tmp[x][y]->dir = 0;
				Get_me()->next.matrix[x][y] = 2;
			}
		}
		else if (x == 0 & y == tmp.size() - 1) {
			if (tmp[x][y]->dir == 1 || tmp[x][y]->dir == -1) {
				tmp[x][y]->dir = 0;
				Get_me()->next.matrix[x][y] = 2;
			}
		}
		else if (x == tmp.size() - 1 & y == 0) {
			if (tmp[x][y]->dir == 1 || tmp[x][y]->dir == -1) {
				tmp[x][y]->dir = 0;
				Get_me()->next.matrix[x][y] = 2;
			}
		}
		else if (x == tmp.size() - 1 & y == tmp.size() - 1) {
			if (tmp[x][y]->dir == 3 || tmp[x][y]->dir == -3) {
				tmp[x][y]->dir = 0;
				Get_me()->next.matrix[x][y] = 2;
			}
		}
	}
	void Next_button::Click(Fl_Widget* pb, void* t) {
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Get_me()->win->begin();
		for (int i = 0; i < tmp.size(); i++) {
			for (int j = 0; j < tmp.size(); j++) {
				tmp[i][j]->Change_dir();
				Get_me()->next.matrix[i][j] = 0;
			}
		}
		for (int t = 0; t < 3; t++) {
			for (int i = 0; i < tmp.size(); i++) {
				for (int j = 0; j < tmp.size(); j++) {
					if (i == 0 || j == 0 || i == tmp.size() - 1 || j < tmp.size())
						Stop_walls(i, j);
					int s = Calc_obj(i, j);
					if (s > 1) {
						Explose(i, j);
						s = Calc_obj(i, j);
					}
					if (s == 1) {
						Transport(i, j);

					}
				}
			}
			for (int i = 0; i < tmp.size(); i++) {
				for (int j = 0; j < tmp.size(); j++) {
				}
			}
			Pos_matrix(Get_me()->next.matrix, -1);
		}
		Pos_matrix(Get_me()->next.matrix, 2);
		Pole::Draw_pole(Get_me()->next.matrix);
		Get_me()->Color_all();
		Get_me()->win->end();
		Get_me()->win->redraw();

	}


	int Next_button::Calc_obj(int x, int y) {
		int size = Get_me()->pole.size;
		int n = 0;
		if (Get_me()->next.matrix[x][y] != 0) {
			n += 1;
		}
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Array<Array<int>>& matrix = Get_me()->next.matrix;
		if (x > 0) {
			if (y > 0) {
				if (tmp[x - 1][y - 1]->dir == -1 && matrix[x - 1][y - 1] != -2) {
					n += 1;
				}
			}
			if (y < size - 1) {
				if (tmp[x - 1][y + 1]->dir == -3 && matrix[x - 1][y + 1] != -2) {
					n += 1;
				}
			}
			if (tmp[x - 1][y]->dir == -2 && matrix[x - 1][y] != -2) {
				n += 1;
			}
		}
		if (x < size - 1) {
			if (y > 0) {
				if (tmp[x + 1][y - 1]->dir == 3 && matrix[x + 1][y - 1] != -2) {
					n += 1;
				}
			}
			if (y < size - 1) {
				if (tmp[x + 1][y + 1]->dir == 1 && matrix[x + 1][y + 1] != -2) {
					n += 1;
				}
			}
			if (tmp[x + 1][y]->dir == 2 && matrix[x + 1][y] != -2) {
				n += 1;
			}
		}
		if (y > 0) {
			if (tmp[x][y - 1]->dir == 4 && matrix[x][y - 1] != -2) {
				n += 1;
			}
		}
		if (y < size - 1) {
			if (tmp[x][y + 1]->dir == -4 && matrix[x][y + 1] != -2) {
				n += 1;
			}
		}
		return n;
	}

	void Next_button::find_dir(int x, int y) {
		int size = Get_me()->pole.size;
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Array<Array<int>>& matrix = Get_me()->next.matrix;
		tmp[x][y]->dir = 0;
		if (x > 0) {
			if (y > 0) {
				if (tmp[x - 1][y - 1]->dir == 0 && matrix[x - 1][y - 1] == 0) {
					matrix[x - 1][y - 1] = 2;
					return;
				}
			}
			if (y < size - 1) {
				if (tmp[x - 1][y + 1]->dir == 0 && matrix[x - 1][y + 1] == 0) {
					matrix[x - 1][y + 1] = 2;
					return;
				}
			}
			if (tmp[x - 1][y]->dir == 0 && matrix[x - 1][y] == 0) {
				matrix[x - 1][y] = 2;
				return;
			}
		}
		if (x < size - 1) {
			if (y > 0) {
				if (tmp[x + 1][y - 1]->dir == 0 && matrix[x + 1][y - 1] == 0) {
					matrix[x + 1][y - 1] = 2;
					return;
				}
			}
			if (y < size - 1) {
				if (tmp[x + 1][y + 1]->dir == 0 && matrix[x + 1][y + 1] == 0) {
					matrix[x + 1][y + 1] = 2;
					return;
				}
			}
			if (tmp[x + 1][y]->dir == 0 && matrix[x + 1][y] == 0) {
				matrix[x + 1][y] = 2;
				return;
			}
		}
		if (y > 0) {
			if (tmp[x][y - 1]->dir == 0 && matrix[x][y - 1] == 0) {
				matrix[x][y - 1] = 2;
				return;
			}
		}
		if (y < size - 1) {
			if (tmp[x][y + 1]->dir == 0 && matrix[x][y + 1] == 0) {
				matrix[x][y + 1] = 2;
				return;
			}
		}
	}
	void Next_button::Explose_help(int x, int y, int dir) {
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Array<Array<int>>& matrix = Get_me()->next.matrix;
		if (tmp[x][y]->dir == dir) {
			if (tmp[x][y]->Info() == 1) {
				Cell::Dublicate_cell(&tmp[x][y]);
			}
			else {
				if (matrix[x][y] > 0)
				{
					find_dir(x, y);
				}
				else {
					tmp[x][y]->dir *= -1;
					matrix[x][y] = -2;
				}
			}
		}
	}

	void Next_button::Explose(int x, int y) {
		int size = Get_me()->pole.size;

		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Array<Array<int>>& matrix = Get_me()->next.matrix;
		Cell* tp;
		if (x > 0) {
			if (y > 0) {
				Explose_help(x - 1, y - 1, -1);
			}
			if (y < size - 1) {
				Explose_help(x - 1, y + 1, -3);
			}
			Explose_help(x - 1, y, -2);
		}
		if (x < size - 1) {
			if (y > 0) {
				Explose_help(x + 1, y - 1, 3);
			}
			if (y < size - 1) {
				Explose_help(x + 1, y + 1, 1);
			}
			Explose_help(x + 1, y, 2);
		}
		if (y > 0) {
			Explose_help(x, y - 1, 4);
		}
		if (y < size - 1) {
			Explose_help(x, y + 1, -4);
		}
		if (tmp[x][y]->dir == 0) {
			if (tmp[x][y]->Info() == 1) {
				Cell::Dublicate_cell(&tmp[x][y]);
			}
		}
	}

	void Next_button::Transport_help(int x, int y, int x_1, int y_1, int  dir) {
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Array<Array<int>>& matrix = Get_me()->next.matrix;
		if (tmp[x + x_1][y + y_1]->dir == dir && matrix[x + x_1][y + y_1] != -2) {
			if (tmp[x + x_1][y + y_1]->Info() == 1) {
				if (matrix[x + x_1][y + y_1] < 0)
					matrix[x + x_1][y + y_1] = 0;
				matrix[x][y] = 1;
			}
			else {
				if (matrix[x + x_1][y + y_1] < 0)
					matrix[x + x_1][y + y_1] = 0;
				matrix[x][y] = 2;
			}
			tmp[x + x_1][y + y_1]->dir = 0;
		}
	}

	void Next_button::Transport(int x, int y) {
		int size = Get_me()->pole.size;
		if (Get_me()->next.matrix[x][y] != 0)
			return;
		Array<Array<Cell*>>& tmp = Get_me()->pole.cells;
		Array<Array<int>>& matrix = Get_me()->next.matrix;
		Cell* tp;
		if (x > 0) {
			if (y > 0) {
				Transport_help(x, y, -1, -1, -1);
			}
			if (y < size - 1) {
				Transport_help(x, y, -1, 1, -3);
			}
			Transport_help(x, y, -1, 0, -2);
		}
		if (x < size - 1) {
			if (y > 0) {
				Transport_help(x, y, 1, -1, 3);
			}
			if (y < size - 1) {
				Transport_help(x, y, 1, 1, 1);
			}
			Transport_help(x, y, 1, 0, 2);
		}
		if (y > 0) {
			Transport_help(x, y, 0, -1, 4);
		}
		if (y < size - 1) {
			Transport_help(x, y, 0, 1, -4);
		}

	}

}