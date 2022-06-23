#include "Special_buttons.h"
#include "Window.h"
namespace Game {
	void Special_buttons::Click(Fl_Widget* pb, void* t) {
		active = pb;
		Get_me()->buttons.Update_local();
	}
	void Special_buttons::Update_local() {
		Deselect_all();
		for (int i = 0; i < 4; i++) {
			if (others[i]->contains(active)) {
				Select(i);
				break;
			}
		}
	}
	Special_buttons::Special_buttons(Fl_Window& w, double size) {
		w.begin();
		for (int i = 0; i < 4; i++) {
			Fl_Button* button = new Fl_Button(0, i * 100 * size, 100 * size, 100 * size, "QU");
			button->callback(Click, nullptr);
			others[i] = button;
			others[i]->labelsize(14 * size);
		}
		Deselect_all();
		Select(0);
		w.end();
	}

	void Special_buttons::Deselect_all() {
		for (int i = 0; i < 4; i++) {
			others[i]->copy_label(NAME[i].c_str());
			others[i]->color(Color_std);
		}
	}
	void Special_buttons::Select(int i) {
		Fl_Color fl = fl_rgb_color(255, 0, 0);
		others[i]->color(fl);
		type = i;
	}

	Special_buttons::~Special_buttons() {
		for (int i = 0; i < 4; i++) {
			delete others[i];
		}
	}
}