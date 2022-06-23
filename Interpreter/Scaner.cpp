#include "Scaner.h"

Ident::Ident():name("") {
}
Ident::Ident(const std::string& s): name(s), type(Types::LEX_ID) {
}
Ident::Ident(const Ident& s):name(s.name), type(s.type), value(s.value), declare(s.declare),assign(s.assign),is_arr(s.is_arr),
arr(s.arr){
}

bool Ident::operator==(const std::string& s) {
	return s == this->name;
}
std::string Ident::get_name() {
	return name;
}
bool Ident::get_declare() {
	return declare;
}
void Ident::set_declare() {
	declare = true;
}
Types Ident::get_type() {
	return type;
}
void Ident::put_type(Types s) {
	type = s;
}
bool Ident::get_assign() {
	return assign;
}
void Ident::set_assign() {
	assign = true;
}
int Ident::get_value() {
	return value;
}
void Ident::set_value(int x) {
	value = x;
}
int Ident::get_tmp() {
	return tmp;
}
void Ident::set_tmp(int x) {
	tmp = x;
}
bool Ident::get_is_arr() {
	return is_arr;
}
void Ident::set_is_arr() {
	is_arr = true;
}






Scaner::Scaner(const char* c) {
	try {
		file.open(c);
		if (!file) {
			throw "Can't open file!";
		}
	}
	catch (std::string){
		std::cout << "!!";
	}
	catch (...){
		;
	}
}

void Scaner::gc() {
	if (ptr < str.size()) {
		ptr++;
		c = str[ptr - 1];
	}
	else if (std::getline(file, str)) {
		ptr = 0;
		c = '\n';
	}
	else {
		ptr++;
		c = '@';
	}
	
}


Scaner::~Scaner() {
	if (file)
		file.close();
}

int Scaner::find(std::string& s, const std::string* list) {
	int i = 0;
	while (list[i]!="FIN") {
		if (s == list[i])
			return i;
		i++;
	}
	return 0;
}

int Scaner::put(const std::string& s) {
	for (int i = 0; i < TID.size(); i++) {
		if (TID[i].get_name() == s) {
			return i;
		}
	}
	TID.push_back(Ident(s));
	return TID.size() - 1;
}

Lex Scaner::get_lex(){
	enum State{H,IDENT,NUM,COM,ALE,NEQ};
	std::string str="";
	State state = H;
	int i = 0, k = 0;
	do {
		gc();
		switch (state) {
		case H:
			if (c == ' ' || c == '\n' || c == '\t' || c=='\0');
			else if (c >= 'a' && c <= 'z') {
				str += c;
				state = IDENT;
			}
			else if (c >= '0' && c <= '9') {
				str += c;
				k = c - '0';
				state = NUM;
			}
			else if (c == '{') {
				state = COM;
			}
			else if (c == ':' || c == '<' || c == '>'||c == '=') {
				str += c;
				state = ALE;
			}
			else if (c == '@') {
				return Lex(Types::LEX_FIN);
			}
			else if (c == '!') {
				str += c;
				state = NEQ;
			}
			else {
				str += c;
				i = find(str, Lex::TD);
				if (i != 0) {
					return Lex((Types)(i + int(Types::LEX_FIN)));
				}
				else
					throw c;
			}
			break;
		case IDENT:
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z') {
				str += c;
			}
			else {
				if (c!='\n')
					ptr--;
				i = find(str, Lex::TW);
				if (i) {
					return Lex((Types)i);
				}
				else {
					i = put(str);
					return Lex(Types::LEX_ID, i);
				}
			}
			break;
		case NUM:
			if (c >= '0' && c <= '9')
				k = k * 10 + c - '0';
			else {
				if (c != '\n')
					ptr--;
				return Lex(Types::LEX_NUM, k);
			}
			break;
		case COM:
			if (c == '}') state = H;
			else if (c == '@') throw "Unexpected end of file";
			break;
		case ALE:
			if (c == '=') {
				str += c;
				i = find(str, Lex::TD);
				return Lex((Types)(i + (int)Types::LEX_FIN));
			}
			else {
				ptr--;
				i = find(str, Lex::TD);
				
				return Lex((Types)(i + (int)Types::LEX_FIN));
			}
			break;
		case NEQ:
			if (c == '=') {
				return Lex(Types::LEX_NEQ);
			}
			else {
				throw c;
			}
		}

	} while (c!='@');
	return Lex(Types::LEX_FIN);
}

int Scaner::add_arr(int n) {
	TID_ARR.push_back(std::vector<int>(0,n));
	return TID_ARR.size() - 1;
}