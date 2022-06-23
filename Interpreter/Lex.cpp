#include "Lex.h"

std::string Lex::TW[20] = { "NULL","and", "or", "begin", "end", "program", "var", "int", "bool", "if", "then","else", "while", "do", "true", "false", "not", "read", "write", "FIN"};
std::string Lex::TD[20] = { "NULL",";",",",":=","+","-","*","/","==","!=",">","<",">=","<=",":","(",")","[","]","FIN" };
Lex::Lex(Types type, int x):t_lex(type), v_lex(x) {}


Types Lex::get_type() {
	return t_lex;
}

int Lex::get_val() {
	return v_lex;
}

void Lex::set_val(int x) {
	v_lex = x;
}

void Lex::set_type(Types x) {
	t_lex = x;
}

std::ostream& operator<<(std::ostream& o, Lex l) {
	if ((int)l.t_lex <= 19)
		o << l.TW[(int)l.t_lex];
	else if ((int)l.t_lex <= 37)
		o << l.TD[(int)l.t_lex - (int)Types::LEX_FIN];
	else if ((int)l.t_lex == 38)
		o << "LEX_NUM";
	else if ((int)l.t_lex == 39)
		o << "LEX_ID";
	else if ((int)l.t_lex == 40)
		o << "POLIZ_LABEL";
	else if ((int)l.t_lex == 41)
		o << "POLIZ_ADDRESS";
	else if ((int)l.t_lex == 42)
		o << "POLIZ_GO";
	else if ((int)l.t_lex == 43)
		o << "POLIZ_FGO";

	return o;
}