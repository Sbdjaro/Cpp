#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <string>

namespace Game {
	void raise_err(std::string s);

	class Cell {
		int pos_x;
		int pos_y;
		int size;
		double start;
		static void Click(Fl_Widget* pb, void*);
	public:
		int dir = 0;
		Fl_Button* button;

		Cell(const int& x, const int& y, const int& size, double start);
		Cell(const Cell& x);
		virtual int Info();
		static void Dublicate_cell(Cell** x);
		static void Dublicate_bubble(Cell** x);
		static void Dublicate_ball(Cell** x);
		static int Rand_dir();
		virtual void Change_dir();
		virtual void Color();
		~Cell();
	};

	class Round : public Cell {
	public:
		Round(const Cell&);
		virtual int Info();
		virtual void Change_dir();
	};

	class Bubble : public Round {
	public:
		Bubble(const Cell&);
		virtual void Color();
		virtual int Info();
		virtual void Change_dir();
	};

	class Ball : public Round {
	public:
		Ball(const Cell&);
		virtual void Color();
		virtual int Info();
		virtual void Change_dir();
	};
}
