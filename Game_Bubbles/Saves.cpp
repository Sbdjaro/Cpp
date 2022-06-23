#include "Saves.h"
#include <string>
#include <iostream>
#include "Window.h"
namespace Game {
	void Save::Load_call(Fl_Widget* pb, void* t) {
		for (int i = 0; i < 3; i++) {
			if (me->load_button[i]->contains(pb)) {
				for (int j = 0; j < me->saves[i].size(); j++) {
					for (int k = 0; k < me->saves[i][j].size(); k++) {
						std::cout << me->saves[i][j][k] << " ";
					}
					std::cout << "\n";
				}
				Pole::Draw_pole(me->saves[i]);
				break;
			}
		}

	}
	void Save::Save_call(Fl_Widget* pb, void* t) {
		int k = 0;
		for (k = 0; k < 3; k++) {
			if (me->save_button[k]->contains(pb)) {
				break;
			}
		}
		me->load_button[k]->color(fl_rgb_color(0, 255, 0));
		Get_me()->win->redraw();
		for (int i = 0; i < me->saves[0].size(); i++) {
			for (int j = 0; j < me->saves[0].size(); j++) {
				me->saves[k][i][j] = Get_me()->pole.cells[i][j]->Info();
			}
		}
	}
	void Save::Random_call(Fl_Widget* pb, void* t) {
		Array<Array<int>> m(me->saves[0].size(), Array<int>(me->saves[0].size(), 0));
		for (int i = 0; i < me->saves[0].size(); i++) {
			for (int j = 0; j < me->saves[0].size(); j++) {
				m[i][j] = rand() % 3;
			}
		}
		Pole::Draw_pole(m);
	}
	void Save::Clear_call(Fl_Widget* pb, void* t) {
		Array<Array<int>> m(me->saves[0].size(), Array<int>(me->saves[0].size(), 0));
		Pole::Draw_pole(m);
	}
	Save::Save(Fl_Window& w, int size, int len) {
		w.begin();
		rand_button = new Fl_Button(600 * size, 0, 100 * size, 100 * size, "Random cells");
		rand_button->labelsize(14 * size);
		rand_button->callback(Random_call);
		rand_button->color(fl_rgb_color(0, 255, 0));
		clear_button = new Fl_Button(600 * size, 400 * size, 100 * size, 100 * size, "Clear pole");
		clear_button->labelsize(14 * size);
		clear_button->callback(Clear_call);
		clear_button->color(fl_rgb_color(102, 51, 0));
		for (int i = 0; i < 3; i++) {
			save_button[i] = new Fl_Button(600 * size, 100 * size * (i + 1), 100 * size, 50 * size, "Save");
			save_button[i]->labelsize(14 * size);
			save_button[i]->callback(Save_call);
			save_button[i]->color(fl_rgb_color(255, 255, 255));
			load_button[i] = new Fl_Button(600 * size, 100 * size * (i + 1) + 50 * size, 100 * size, 50 * size, "Load");
			load_button[i]->labelsize(14 * size);
			load_button[i]->callback(Load_call);
			load_button[i]->color(fl_rgb_color(255, 0, 0));
			saves[i] = Array<Array<int>>(len, Array<int>(len, 0));
		}
		w.end();
		me = this;
	}

	Save::~Save() {
		delete rand_button;
		for (int i = 0; i < 3; i++) {
			delete save_button[i];
			delete load_button[i];
		}
	}
}