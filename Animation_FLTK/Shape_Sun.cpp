#include "Shape_Sun.h"
namespace Game {
	Sun::Sun() : Image(new Quad(100, 0, 200, 0, 200, 100, 100, 100, 3), std::vector<std::vector<int>>(2, std::vector<int>(2, 0))) {
		Simple* tr;
		Image* im;

		tr = new Triangle(20, 20, 100, 10, 100, 50, 3);
		std::vector<std::vector<int>> f(4, std::vector<int>(2, 0));
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = -10, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = 10;
		im = new Image(tr, f);
		Add_son(im);

		tr = new Triangle(20, 80, 100, 50, 100, 90, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = -10, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = 10;
		im = new Image(tr, f);
		Add_son(im);


		tr = new Triangle(100, 70, 130, 100, 60, 140, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = 0, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = 0;
		im = new Image(tr, f);
		Add_son(im);


		tr = new Triangle(110, 100, 150, 100, 120, 180, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = -10; f[1][1] = 00, f[2][0] = 0; f[2][1] = 0; f[3][0] = 10; f[3][1] = 00;
		im = new Image(tr, f);
		Add_son(im);

		tr = new Triangle(150, 100, 190, 100, 180, 180, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = -10; f[1][1] = 00, f[2][0] = 0; f[2][1] = 0; f[3][0] = 10; f[3][1] = 00;
		im = new Image(tr, f);
		Add_son(im);


		tr = new Triangle(170, 100, 200, 70, 240, 140, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = 0, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = 0;
		im = new Image(tr, f);
		Add_son(im);


		tr = new Triangle(200, 90, 200, 50, 280, 80, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = 10, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = -10;
		im = new Image(tr, f);
		Add_son(im);

		tr = new Triangle(200, 50, 200, 10, 280, 20, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = 10, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = -10;
		im = new Image(tr, f);
		Add_son(im);


		tr = new Triangle(170, 0, 200, 30, 240, -40, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = 0, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = 0;
		im = new Image(tr, f);
		Add_son(im);


		tr = new Triangle(110, 0, 150, 0, 120, -80, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 10; f[1][1] = 0, f[2][0] = 0; f[2][1] = 0; f[3][0] = -10; f[3][1] = 0;
		im = new Image(tr, f);
		Add_son(im);

		tr = new Triangle(150, 0, 190, 0, 180, -80, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 10; f[1][1] = 0, f[2][0] = 0; f[2][1] = 0; f[3][0] = -10; f[3][1] = 0;
		im = new Image(tr, f);
		Add_son(im);


		tr = new Triangle(100, 30, 130, 0, 60, -40, 3);
		f[0][0] = 0; f[0][1] = 0; f[1][0] = 0; f[1][1] = 0, f[2][0] = 0; f[2][1] = 0; f[3][0] = 0; f[3][1] = 0;
		im = new Image(tr, f);
		Add_son(im);

	}
}