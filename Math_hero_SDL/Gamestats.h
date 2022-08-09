#pragma once
#include "SDL.h"
#include <ctime>
using namespace std;
class Stats {
	
	long prev_time = (long)std::time(nullptr);
	int spawn_speed=5;
	int heal=2;
	int multiplier=10;
	int time_to_spawn = 0;
	int time_to_heal = 0;
	bool start = true;
public:
	long time = 0;
	void Check();
	void Spawn();
	void Heal();
	void Restart();
};