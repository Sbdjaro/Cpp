#pragma once
#include <fstream>
#include "Lex.h"
#include <vector>


class Ident {
	std::string name;
	bool declare = false;
	Types type = Types::LEX_NULL;
	bool assign = false;
	int value = 0;
	int tmp = -1;
	bool is_arr = false;
public:

	std::vector<int> arr;
	Ident();
	Ident(const std::string& s);
	Ident(const Ident&);
	bool operator==(const std::string& s);
	std::string get_name();
	bool get_declare();
	void set_declare();
	Types get_type();
	void put_type(Types s);
	bool get_assign();
	void set_assign();
	int get_value();
	void set_value(int x);
	int get_tmp();
	void set_tmp(int x);
	bool get_is_arr();
	void set_is_arr();
};



class Scaner {
	std::ifstream file;
	std::string str;
	int ptr=0;
	char c;
	void gc();
	int find(std::string& s,const std::string* list);
public:
	std::vector<Ident> TID;
	std::vector<std::vector<int>> TID_ARR;
	int put(const std::string&);
	Scaner(const char* s);
	Lex get_lex();
	int add_arr(int n);
	~Scaner();
};