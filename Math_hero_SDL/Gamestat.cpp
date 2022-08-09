#include "Gamestats.h"
#include "Window.h"
void Stats::Check() {
	long cur_time= (long)std::time(nullptr);
	if (cur_time - prev_time >= 1) {
		time += cur_time - prev_time;
		prev_time += cur_time - prev_time;
		time_to_spawn += cur_time - prev_time;
		Window::me->pole->panel->health->Add(heal);
		if (time_to_spawn > multiplier)
			Spawn();
	}
	if (time > spawn_speed * multiplier) {
		spawn_speed++;
		if (spawn_speed % 10 == 0)
			multiplier++;
	}
	if (start) {
		start = false;
		Spawn();
	}
}

void Stats::Spawn(){
	time_to_spawn = 0;
	for (int i = 0; i < spawn_speed; i++)
		Window::me->pole->enemies->Add();
}

void Stats::Heal(){
	time_to_heal = 0;
	Window::me->pole->panel->health->Add(heal);
}

void Stats::Restart(){
	heal = 2;
	spawn_speed = 5;
	multiplier = 10;
	time_to_heal = 0;
	time_to_spawn = 0;
	start = true;
	time = 0;
}
