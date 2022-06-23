#include "Shape_Cat.h"
namespace Game {
	Cat::Cat() : Image(new Quad(50, 50, 150, 50, 150, 150, 50, 150, 5), std::vector<std::vector<int>>(2, std::vector<int>(2, 0))) {
		Simple* tr;
		Image* im;
		std::vector<std::vector<int>> f2(2, std::vector<int>(2, 0));
		std::vector<std::vector<int>> f4(4, std::vector<int>(2, 0));
		std::vector<std::vector<int>> f100(100, std::vector<int>(2, 0));
		for (int i = 0; i < 50; i++) {
			f100[i][1] = 0;
			f100[i][0] = i;
		}
		for (int i = 0; i < 50; i++) {
			f100[i + 50][1] = 0;
			f100[i + 50][0] = 50 - i;
		}
		Change_dir(f100, 3);
		tr = new Triangle(50, 50, 90, 50, 70, 0, 5);//ears L back
		f2[0][0] = 0; f2[0][1] = 0; f2[1][0] = 0; f2[1][1] = 0;
		im = new Image(tr, f2);
		Add_son(im);

		tr = new Triangle(110, 50, 150, 50, 130, 0, 5);//ears R back
		f2[0][0] = 0; f2[0][1] = 0; f2[1][0] = 0; f2[1][1] = 0;
		im = new Image(tr, f2);
		Add_son(im);

		tr = new Triangle(60, 50, 80, 50, 70, 20, 7);//ears L top
		for (int i = 0; i < 50; i++) {
			f100[i][0] = 0;
			double t = -5 * i / 50;
			f100[i][1] = t;
		}
		for (int i = 0; i < 50; i++) {
			f100[i + 50][0] = 0;
			double t = -5 + 5 * i / 50;
			f100[i + 50][1] = t;
		}
		im = new Image(tr, f100, 3);
		Add_son(im);

		tr = new Triangle(120, 50, 140, 50, 130, 20, 7);//ears R top
		im = new Image(tr, f100, 3);
		Add_son(im);

		tr = new Quad(65, 80, 90, 80, 90, 105, 65, 105, 0);//eye L back
		f2[0][0] = 0; f2[0][1] = 0; f2[1][0] = 0; f2[1][1] = 0;
		im = new Image(tr, f2);
		Add_son(im);

		tr = new Quad(110, 80, 135, 80, 135, 105, 110, 105, 0);//eye R back
		f2[0][0] = 0; f2[0][1] = 0; f2[1][0] = 0; f2[1][1] = 0;
		im = new Image(tr, f2);
		Add_son(im);

		tr = new Triangle(70, 100, 85, 100, 78, 85, 7);//eye L top
		for (int i = 0; i < 25; i++) {
			f100[i][1] = 0;
			double t = 5 * i / 50;
			f100[i][0] = t;
		}
		for (int i = 0; i < 25; i++) {
			f100[i + 25][1] = 0;
			double t = 5 - 5 * i / 50;
			f100[i + 25][0] = t;
		}
		for (int i = 0; i < 25; i++) {
			f100[i + 50][1] = 0;
			double t = -5 * i / 50;
			f100[i + 50][0] = t;
		}
		for (int i = 0; i < 25; i++) {
			f100[i + 75][1] = 0;
			double t = -5 + 5 * i / 50;
			f100[i + 75][0] = t;
		}
		im = new Image(tr, f100, 5);
		Add_son(im);

		tr = new Triangle(130, 100, 115, 100, 122, 85, 7);//eye R top
		im = new Image(tr, f100, 5);
		Add_son(im);

		tr = new Triangle(100, 115, 90, 135, 110, 135, 0);//nose
		for (int i = 0; i < 50; i++) {
			f100[i][0] = 0;
			double t = 3 * i / 50;
			f100[i][1] = t;
		}
		for (int i = 0; i < 50; i++) {
			f100[i + 50][0] = 0;
			double t = 3 - 5 * i / 50;
			f100[i + 50][1] = t;
		}
		im = new Image(tr, f100, 2);
		Add_son(im);

		tr = new Triangle(78, 120, 35, 100, 45, 95, fl_rgb_color(106, 66, 47));//moustace 1
		for (int i = 0; i < 25; i++) {
			f100[i][1] = 0;
			double t = 3 * i / 50;
			f100[i][0] = t;
		}
		for (int i = 0; i < 25; i++) {
			f100[i + 25][1] = 0;
			double t = 3 - 3 * i / 50;
			f100[i + 25][0] = t;
		}
		for (int i = 0; i < 25; i++) {
			f100[i + 50][1] = 0;
			double t = -3 * i / 50;
			f100[i + 50][0] = t;
		}
		for (int i = 0; i < 25; i++) {
			f100[i + 75][1] = 0;
			double t = -3 + 3 * i / 50;
			f100[i + 75][0] = t;
		}
		im = new Image(tr, f100);
		Add_son(im);

		tr = new Triangle(78, 130, 35, 130, 45, 140, fl_rgb_color(106, 66, 47));//moustace 2
		im = new Image(tr, f100);
		Add_son(im);
		for (int i = 0; i < 100; i++)
			f100[i][0] *= -1;

		tr = new Triangle(122, 120, 165, 100, 155, 95, fl_rgb_color(106, 66, 47));//moustace3
		im = new Image(tr, f100);
		Add_son(im);

		tr = new Triangle(122, 130, 165, 130, 155, 140, fl_rgb_color(106, 66, 47));//moustace 4
		im = new Image(tr, f100);
		Add_son(im);
	}
}