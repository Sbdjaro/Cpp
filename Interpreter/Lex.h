#pragma once
#include <iostream>
#include <string>
#include <vector>




enum class Types {
	LEX_NULL,

	LEX_AND,LEX_OR,LEX_BEGIN,LEX_END,LEX_PROGRAM,LEX_VAR,LEX_INT,LEX_BOOL,
	LEX_IF,LEX_THEN,LEX_ELSE,LEX_WHILE,LEX_DO,LEX_TRUE,LEX_FALSE,LEX_NOT,LEX_READ,LEX_WRITE,

	LEX_FIN,

	LEX_SEMICOLON,LEX_COMMA,LEX_ASSIGN,LEX_PLUS,LEX_MINUS,LEX_MUL,LEX_DIV,LEX_EQ,LEX_NEQ,LEX_G,LEX_L,LEX_GE,LEX_LE,
	LEX_COLON,LEX_STAPLES_ON,LEX_STAPLES_OFF, LEX_ARR_ON, LEX_ARR_OFF,

	LEX_NUM,
	LEX_ID,
	LEX_MASS,
	POLIZ_LABEL,
	POLIZ_ADDRESS,
	POLIZ_GO,
	POLIZ_FGO
};
class Lex {
	Types t_lex;
	int v_lex;
public:
	static std::string TW[20];
	static std::string TD[20];
	Lex(Types type = Types::LEX_NULL, int x = 0);

	Types get_type();
	int get_val();
	void set_val(int x);
	void set_type(Types);

	friend std::ostream& operator<<(std::ostream& o, Lex l);
};



std::ostream& operator<<(std::ostream& o, Lex l);