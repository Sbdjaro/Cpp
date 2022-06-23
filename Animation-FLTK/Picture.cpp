#include "Picture.h"
namespace Game {
	Picture::Picture() : Image(new Quad(0, 0, 0, 1, 1, 1, 1, 0, 6), std::vector<std::vector<int>>(1, std::vector<int>(2, 0)), 100) {
		Simple* tr;
		Image* im;


		std::vector<std::vector<int>> f500(500, std::vector<int>(2, 0));
		std::vector<std::vector<int>> f1(1, std::vector<int>(2, 0));

		tr = new Quad(0, 0, 700, 0, 700, 300, 0, 300, 6);
		im = new Image(tr, f1);
		Add_son(im);

		Sun* s = new Sun();
		s->Move(500, 0);
		Add_son(s);


		Cloud* c = new Cloud();
		Add_son(c);
		c = new Cloud();
		c->Move(200, 40);
		Add_son(c);
		c = new Cloud();
		c->Move(350, 20);
		Add_son(c);
		c = new Cloud();
		c->Move(320, 105);
		Add_son(c);
		c = new Cloud();
		c->Move(600, 20);
		Add_son(c);
		c = new Cloud();
		c->Move(500, 110);
		Add_son(c);
		c = new Cloud();
		c->Move(50, 80);
		Add_son(c);
		c = new Cloud();
		c->Move(-80, 100);
		Add_son(c);
		c = new Cloud();
		c->Move(-170, 0);
		Add_son(c);
		c = new Cloud();
		c->Move(-260, 80);
		Add_son(c);
		c = new Cloud();
		c->Move(-300, 10);
		Add_son(c);
		tr = new Quad(0, 300, 700, 300, 700, 500, 0, 500, 2);
		im = new Image(tr, f1);
		Add_son(im);
		Tree* t = new Tree();
		Add_son(t);

		Tree* tt = new Tree();
		tt->Resize(2);
		tt->Move(300, 150);
		Add_son(tt);

		Tree* ttt = new Tree();
		ttt->Resize(2);
		ttt->Move(400, 170);
		Add_son(ttt);

		Tree* t2 = new Tree();
		t2->Move(500, 50);
		Add_son(t2);



		Cat* cc = new Cat();
		cc->Resize(2);
		cc->Move(350, 400);
		Add_son(cc);
	}
}