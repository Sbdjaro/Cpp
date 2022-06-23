#pragma once
#include <vector>
#include <FL/fl_draw.H>
#include "Simple.h"
namespace Game {
	class Shape {
	public:
		virtual void Draw(int x, int y) = 0;
		virtual void Move(int x, int y) = 0;
		virtual void Resize(int t) = 0;
	};


	class Image : public Shape {

		std::vector<Shape*> sons;
		Simple* form;
		std::vector<std::vector<int>> timepos;
		int iter = 0;
		int speed = 1;

	public:
		Image(std::vector<Shape*> other, Simple* form, std::vector<std::vector<int>> time, int sp = 1);
		Image(Simple* form, std::vector<std::vector<int>> time, int sp = 1);
		Image();

		void Add_son(Shape*);
		void Change_dir(std::vector<std::vector<int>>, int x = -1);

		void Draw(int x, int y);
		void Move(int x, int y);
		void Resize(int t);

		~Image();
	};
}
