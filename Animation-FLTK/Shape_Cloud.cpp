#include "Shape_Cloud.h"
namespace Game {
	Cloud::Cloud() : Image(new Quad(0, 0, 100, 0, 100, 50, 0, 50, 0), std::vector<std::vector<int>>(1, std::vector<int>(2, 0))) {
		Simple* tr;
		Image* im;
		std::vector<std::vector<int>> f100(100, std::vector<int>(2, 0));
		std::vector<std::vector<int>> f1(1, std::vector<int>(2, 0));
		for (int i = 0; i < 100; i += 1)
			f100[i][0] = i * 4;
		Change_dir(f100);
		tr = new Quad(2, 2, 98, 2, 98, 48, 2, 48, 7);
		im = new Image(tr, f1);
		Add_son(im);
	}
}