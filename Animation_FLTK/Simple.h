#pragma once
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

namespace Game {
	class Simple : public Fl_Box {
	public:
		virtual void draw() = 0;
		virtual void draw(int x, int y) = 0;
		virtual void move(int x, int y) = 0;
		virtual void mult(int t) = 0;
		Simple();
	};
	class Triangle : public Simple {

		int x0, y0, x1, x2, y1, y2;
		Fl_Color color;
	public:
		int tmpx = 0, tmpy = 0;
		virtual void draw();
		virtual void draw(int x, int y);
		virtual void move(int x, int y);
		virtual void mult(int t);
		Triangle(int x0, int y0, int x1, int y1, int x2, int y2, Fl_Color color);
	};

	class Quad : public Simple {

		int x0, y0, x1, x2, y1, y2, x3, y3;
		Fl_Color color;
	public:
		int tmpx = 0, tmpy = 0;
		virtual void draw();
		virtual void draw(int x, int y);
		virtual void move(int x, int y);
		virtual void mult(int t);
		Quad(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, Fl_Color color);
	};
}

