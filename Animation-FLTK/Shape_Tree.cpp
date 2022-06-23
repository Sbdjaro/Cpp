#include "Shape_Tree.h"
namespace Game {
	Tree::Tree() : Image(new Quad(100, 400, 150, 400, 150, 200, 100, 200, fl_rgb_color(106, 66, 47)), std::vector<std::vector<int>>(2, std::vector<int>(2, 0))) {
		Simple* tr;
		Image* im;
		std::vector<std::vector<int>> f2(2, std::vector<int>(2, 0));
		std::vector<std::vector<int>> f100(100, std::vector<int>(2, 0));
		for (int i = 0; i < 50; i++) {
			f100[i][0] = 0;
			double t = -20 * i / 50;
			f100[i][1] = t;
		}
		for (int i = 0; i < 50; i++) {
			f100[i + 50][0] = 0;
			double t = -20 + 20 * i / 50;
			f100[i + 50][1] = t;
		}

		tr = new Triangle(0, 400, 250, 400, 125, 250, fl_rgb_color(1, 120, 28));
		im = new Image(tr, f100, 2);
		Add_son(im);

		tr = new Triangle(25, 325, 225, 325, 125, 200, fl_rgb_color(1, 120, 28));
		im = new Image(tr, f100, 2);
		Add_son(im);

		tr = new Triangle(50, 250, 200, 250, 125, 150, fl_rgb_color(1, 120, 28));
		im = new Image(tr, f100, 2);
		Add_son(im);

	}
}