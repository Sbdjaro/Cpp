#include "Simple.h"
#include <iostream>
namespace Game {

	Simple::Simple() : Fl_Box(0, 0, 1, 1, "") {}

	void Triangle::draw() {
		fl_color(color);
		fl_polygon(x0 + tmpx, y0 + tmpy, x1 + tmpx, y1 + tmpy, x2 + tmpx, y2 + tmpy);
	}


	void Triangle::draw(int x, int y) {
		tmpx = x;
		tmpy = y;
		draw();
	}

	void Triangle::move(int x, int y) {
		x0 += x; x1 += x; x2 += x;
		y0 += y; y1 += y; y2 += y;
	}
	void Triangle::mult(int t) {
		x0 /= t; x1 /= t; x2 /= t;
		y0 /= t; y1 /= t; y2 /= t;
	}

	Triangle::Triangle(int x0, int y0, int x1, int y1, int x2, int y2, Fl_Color color) : x0(x0), x1(x1), x2(x2),
		y0(y0), y1(y1), y2(y2), color(color) {
	}
	void Quad::draw() {
		fl_color(color);
		fl_polygon(x0 + tmpx, y0 + tmpy, x1 + tmpx, y1 + tmpy, x2 + tmpx, y2 + tmpy, x3 + tmpx, y3 + tmpy);
	}
	void Quad::draw(int x, int y) {
		tmpx = x;
		tmpy = y;
		draw();
	}

	void Quad::move(int x, int y) {
		x0 += x; x1 += x; x2 += x; x3 += x;
		y0 += y; y1 += y; y2 += y; y3 += y;
	}
	void Quad::mult(int t) {
		x0 /= t; x1 /= t; x2 /= t; x3 /= t;
		y0 /= t; y1 /= t; y2 /= t; y3 /= t;
	}

	Quad::Quad(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, Fl_Color color) : x0(x0), x1(x1),
		x2(x2), y0(y0), y1(y1), y2(y2), x3(x3), y3(y3), color(color) {
	}
}