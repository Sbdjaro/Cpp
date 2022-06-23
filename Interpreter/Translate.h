#pragma once
#include "Scaner.h"

class Translate {
	Scaner sc;
	Lex lex;
	Types type;
	int val;
	std::vector<int> stack;
	std::vector<Types> signs;
	void P(); void D1(); void D2(); void D(); void I();
	void I1(); void I2(); void B(); void S1(); void S(); void E();
	void E1(); void T(); void F();
	void gl();
	void straples();
	void push(Types t);
	bool cmp(Types t, Types d);
public:
	std::vector<Lex> poliz;
	std::vector<int[2]> array_tmp;
	Translate(const char* s);
	bool analize();
	void execute();
	void print_TID();
};