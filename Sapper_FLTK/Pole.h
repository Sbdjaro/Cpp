#pragma once
#include <vector>
#include "Cell.h"
#include <stack>
using namespace std;
class Pole {
public:
	vector<vector<int>> open;
	vector<vector<int>> full;
	vector<vector<int>> table;
	vector<vector<Cell*>> cells;
	Fl_Box* bg;
	int bomb;
	int opened;
	int size;
	int flag = 0;
	bool active=true;
	bool start = true;
	Pole(int size, int bomb);
	void Generate(int x, int y);
	void Calc();
	void Draw();
	vector<int> What_Button(Fl_Widget* pb);
	void Update(vector<int>);
	void Flag(vector<int>);
	void Game_Over();
	void Game_Win();
	void Restart();
	~Pole();
};