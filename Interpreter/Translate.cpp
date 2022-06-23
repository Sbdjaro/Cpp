#include "Translate.h"
#include <stack>
Translate::Translate(const char* s): sc(s){}

void Translate::gl() {
	lex = sc.get_lex();
	type = lex.get_type();
	val = lex.get_val();
	
}

bool Translate::analize() {
	gl();
	P();
	if (type != Types::LEX_FIN) throw lex;
	execute();

	return true;
}

void Translate::execute() {
	Lex l, l1;
	int k, p;
	std::stack <Lex> stack1;
	for (int i = 0; i < poliz.size(); i++) {
		switch (poliz[i].get_type()) {
		case Types::LEX_ID:
		case Types::LEX_NUM:
		case Types::POLIZ_LABEL:
		case Types::LEX_FALSE:
		case Types::LEX_TRUE:
			stack1.push(poliz[i]);
			break;
		case Types::LEX_WRITE:
			if (stack1.top().get_type() == Types::LEX_ID)
				if (sc.TID[stack1.top().get_val()].get_assign())
					std::cout << sc.TID[stack1.top().get_val()].get_value() << '\n';
				else throw "Необьявленная переменная";
			else
				
				std::cout << stack1.top().get_val()<<'\n';
			stack1.pop(); 
			
			break;
		case Types::POLIZ_GO:
			l = stack1.top();
			stack1 = std::stack <Lex>();
			i = l.get_val() - 1;
			break;
		case Types::POLIZ_FGO:
			l = stack1.top();
			stack1.pop(); 
			if (!(stack1.top().get_type() == Types::LEX_ID && sc.TID[stack1.top().get_val()].get_type()==Types::LEX_BOOL) && stack1.top().get_type() != Types::LEX_TRUE
				&& stack1.top().get_type() != Types::LEX_FALSE) throw "Неверный оператор сравнения";
			if (stack1.top().get_type() == Types::LEX_ID) {
				if (sc.TID[stack1.top().get_val()].get_assign())
					if (sc.TID[stack1.top().get_val()].get_value() == 1)
						stack1 = std::stack <Lex>();
					else { i = l.get_val() - 1; stack1 = std::stack <Lex>(); }
				else throw "Переменная неинициализированна";
			}
			else if (stack1.top().get_type() == Types::LEX_TRUE) stack1 = std::stack <Lex>();
			else if (stack1.top().get_type() == Types::LEX_FALSE) { stack1 = std::stack <Lex>(); i = l.get_val() - 1; }//Очистка стека
			break;
		case Types::LEX_ARR_OFF:
			l = stack1.top();
			stack1.pop();
			l1 = stack1.top();
			stack1.pop();
			k = 0;
			if (l.get_type() == Types::LEX_NUM) k = l.get_val();
			else if (l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_INT && sc.TID[l.get_val()].get_assign())
				k = sc.TID[l.get_val()].get_value();
			else throw "Неверный параметр массива";
			if (sc.TID[l1.get_val()].get_is_arr()) {
				if (sc.TID[l1.get_val()].get_type() == Types::LEX_INT) {
					if (k >= sc.TID[l1.get_val()].arr.size()) throw "Выход за границу массива";
					stack1.push(Lex(Types::LEX_NUM, sc.TID[l1.get_val()].arr[k]));
				}
				else if (sc.TID[l1.get_val()].get_type() == Types::LEX_BOOL) {
					if (l.get_val() >= sc.TID[l1.get_val()].arr.size()) throw "Выход за границу массива";
					stack1.push(sc.TID[l1.get_val()].arr[k]==1?Types::LEX_TRUE: Types::LEX_FALSE);
				}
			}
			else throw "Неверный индекс массива";
			break;
		case Types::LEX_ARR_ON:
			l = stack1.top();
			stack1.pop();
			l1 = stack1.top();
			stack1.pop();
			k = 0;
			if (l.get_type() == Types::LEX_NUM) k = l.get_val();
			else if (l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_INT && sc.TID[l.get_val()].get_assign())
				k = sc.TID[l.get_val()].get_value();
			else throw "Неверный параметр массива";
			if (sc.TID[l1.get_val()].get_is_arr()) {
				if (k >= sc.TID[l1.get_val()].arr.size()) throw "Выход за границу массива";
				sc.TID[l1.get_val()].set_tmp(k);
				stack1.push(l1);
			}
			else throw "Не массив";
			break;
		
		case Types::LEX_PLUS:
		case Types::LEX_DIV:
		case Types::LEX_MINUS:
		case Types::LEX_MUL:
		case Types::LEX_NEQ:
		case Types::LEX_EQ:
		case Types::LEX_G:
		case Types::LEX_L:
		case Types::LEX_GE:
		case Types::LEX_LE:
			l = stack1.top();
			stack1.pop();
			l1 = stack1.top();
			stack1.pop();
			if (l.get_type() == Types::LEX_NUM || (l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_INT) &&
				l1.get_type() == Types::LEX_NUM || (l1.get_type() == Types::LEX_ID && sc.TID[l1.get_val()].get_type() == Types::LEX_INT)) {
				k = 0;
				if (l.get_type() == Types::LEX_NUM)
					k += l.get_val();
				else if (sc.TID[l.get_val()].get_assign())
					k += sc.TID[l.get_val()].get_value();
				else throw "Необьявленная переменная";
				p = 0;
				if (l1.get_type() == Types::LEX_NUM)
					p += l1.get_val();
				else if (sc.TID[l1.get_val()].get_assign())
					p += sc.TID[l1.get_val()].get_value();
				else throw "Необьявленная переменная";
				switch (poliz[i].get_type()) {
				case Types::LEX_PLUS: stack1.push(Lex(Types::LEX_NUM, k + p)); break;
				case Types::LEX_DIV: stack1.push(Lex(Types::LEX_NUM, p / k)); break;
				case Types::LEX_MINUS: stack1.push(Lex(Types::LEX_NUM, p - k)); break;
				case Types::LEX_MUL: stack1.push(Lex(Types::LEX_NUM, k * p)); break;
				case Types::LEX_NEQ: if (k != p) stack1.push(Lex(Types::LEX_TRUE)); 
								   else stack1.push(Lex(Types::LEX_FALSE)); break;
				case Types::LEX_EQ: if (k == p) stack1.push(Lex(Types::LEX_TRUE));
								  else stack1.push(Lex(Types::LEX_FALSE)); break;
				case Types::LEX_G: if (p > k) stack1.push(Lex(Types::LEX_TRUE));
								 else stack1.push(Lex(Types::LEX_FALSE)); break;
				case Types::LEX_L: if (p < k) stack1.push(Lex(Types::LEX_TRUE));
								 else stack1.push(Lex(Types::LEX_FALSE)); break;
				case Types::LEX_GE: if (p >= k) stack1.push(Lex(Types::LEX_TRUE));
								  else stack1.push(Lex(Types::LEX_FALSE)); break;
				case Types::LEX_LE: if (p <= k) stack1.push(Lex(Types::LEX_TRUE));
								  else stack1.push(Lex(Types::LEX_FALSE)); break;
				}
				
			}
			else throw "Ошибка с арифметическими операциями";
			break;
		case Types::LEX_ASSIGN:
			l = stack1.top();
			stack1.pop();
			l1 = stack1.top();
			stack1.pop();
			if ((l1.get_type() == Types::LEX_ID && sc.TID[l1.get_val()].get_type() == Types::LEX_INT) && (l.get_type() == Types::LEX_NUM|| l.get_type() == Types::LEX_ID&& sc.TID[l.get_val()].get_type() == Types::LEX_INT)) {
				k = 0;
				if (l.get_type() == Types::LEX_NUM)
					k = l.get_val();
				else if (!sc.TID[l.get_val()].get_assign()) throw "Неинициализированная переменная";
				else k = sc.TID[l.get_val()].get_value();
				if (sc.TID[l1.get_val()].get_is_arr()) {
					if (sc.TID[l1.get_val()].get_tmp() == -1) throw "Неверное использование массива";
					sc.TID[l1.get_val()].arr[sc.TID[l1.get_val()].get_tmp()] = k;
					sc.TID[l1.get_val()].set_assign();
				}
				else {
					sc.TID[l1.get_val()].set_value(k);
					sc.TID[l1.get_val()].set_assign();
				}
				stack1.push(Lex(Types::LEX_NUM, k));

			}
			else if ((l1.get_type() == Types::LEX_ID && sc.TID[l1.get_val()].get_type() == Types::LEX_BOOL) && (l.get_type() == Types::LEX_TRUE || l.get_type() == Types::LEX_FALSE|| l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_INT)) {
				k = 0;
				if (l.get_type() == Types::LEX_TRUE)
					k = 1;
				else if (l.get_type() == Types::LEX_FALSE)
					k = 0;
				else if (!sc.TID[l.get_val()].get_assign()) throw "Неинициализированная переменная";
				else k = sc.TID[l.get_val()].get_value();
				if (sc.TID[l1.get_val()].get_is_arr()) {
					if (sc.TID[l1.get_val()].get_tmp() == -1) throw "Неверное использование массива";
					sc.TID[l1.get_val()].arr[sc.TID[l1.get_val()].get_tmp()] = k;
				}
				else {
					sc.TID[l1.get_val()].set_value(k);
					sc.TID[l1.get_val()].set_assign();
				}
				stack1.push(k==1?Types::LEX_TRUE:Types::LEX_FALSE);
			}
			else throw "Ошибка с присваиванием";
			break;
		case Types::LEX_SEMICOLON:
			stack1 = std::stack <Lex>();
			break;
		
		case Types::LEX_NOT:
			l = stack1.top();
			stack1.pop();
			if (l.get_type() == Types::LEX_TRUE){
				stack1.push(Lex(Types::LEX_FALSE));
			}
			else if (l.get_type() == Types::LEX_FALSE) {
				stack1.push(Lex(Types::LEX_TRUE));
			}
			else if (l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_BOOL) {
				if (!sc.TID[l.get_val()].get_assign()) throw "Необьявленная переменная";
				if (sc.TID[l.get_val()].get_value() == 0) {
					stack1.push(Lex(Types::LEX_TRUE));
				}
				else if (sc.TID[l.get_val()].get_value() == 1) {
					stack1.push(Lex(Types::LEX_FALSE));
				}
			}
			else throw "Неподходящий тип для NOT";
			break;
		
		case Types::LEX_AND:
		case Types::LEX_OR:
			l = stack1.top();
			stack1.pop();
			l1 = stack1.top();
			stack1.pop();
			if (l.get_type() == Types::LEX_TRUE) {
				k = 1;
			}
			else if (l.get_type() == Types::LEX_FALSE) {
				k = 0;
			}
			else if (l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_BOOL) {
				if (!sc.TID[l.get_val()].get_assign()) throw "Необьявленная переменная";
				k = sc.TID[l.get_val()].get_value();
			}
			else throw "Неверный тип для логической операции";
			if (l1.get_type() == Types::LEX_TRUE) {
				p = 1;
			}
			else if (l1.get_type() == Types::LEX_FALSE) {
				p = 0;
			}
			else if (l1.get_type() == Types::LEX_ID && sc.TID[l1.get_val()].get_type() == Types::LEX_BOOL) {
				if (!sc.TID[l1.get_val()].get_assign()) throw "Необьявленная переменная";
				p = sc.TID[l1.get_val()].get_value();
			}
			else throw "Неверный тип для логической операции";
			if (poliz[i].get_type() == Types::LEX_AND)
				if (p == k && p == 1) stack1.push(Types::LEX_TRUE);
				else stack1.push(Types::LEX_FALSE);
			else if (p == k && p == 0) stack1.push(Types::LEX_FALSE);
			else stack1.push(Types::LEX_TRUE);
			break;
		case Types::LEX_READ:
			l = stack1.top();
			stack1.pop();
			if ((l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_BOOL)) {
				bool t;
				std::cin >> t;
				if (sc.TID[l.get_val()].get_is_arr()) {
					if (sc.TID[l.get_val()].get_tmp() == -1) throw "Неверная работа с массивом";
					if (t)
						sc.TID[l.get_val()].arr[sc.TID[l.get_val()].get_tmp()] = 1;
					else sc.TID[l.get_val()].arr[sc.TID[l.get_val()].get_tmp()] = 0;
				}
				else if (t) {
					sc.TID[l1.get_val()].set_assign();
					sc.TID[l1.get_val()].set_value(1);
				}
				else {
					sc.TID[l1.get_val()].set_value(0);
					sc.TID[l1.get_val()].set_assign();
				}
			}
			else if ((l.get_type() == Types::LEX_ID && sc.TID[l.get_val()].get_type() == Types::LEX_INT)) {
				int t;
				std::cin >> t;
				if (sc.TID[l.get_val()].get_is_arr()) {
					if (sc.TID[l.get_val()].get_tmp() == -1) throw "Неверная работа с массивом";
					sc.TID[l.get_val()].arr[sc.TID[l.get_val()].get_tmp()] = t;

				}
				else {
					sc.TID[l1.get_val()].set_value(t);
					sc.TID[l1.get_val()].set_assign();
				}
			}
			break;
		}

	}
}

void Translate::P() {
	if (type != Types::LEX_PROGRAM) {
		throw lex;
	}
	gl();
	D1();
	if (type != Types::LEX_SEMICOLON) throw lex;
	gl();
	poliz.clear();
	B();
}

void Translate::D1() {
	if (type != Types::LEX_VAR) {
		throw lex;
	}
	gl();
	D2();
}

void Translate::D2() {
	D();
	while (type == Types::LEX_COMMA) {
		gl();
		D();
	}
}

void Translate::D() {
	I1();
	if (type != Types::LEX_COLON) throw lex;
	gl();
	if (type != Types::LEX_INT && type != Types::LEX_BOOL) throw lex;
	
	if (type == Types::LEX_INT) {
		gl();
		if (type == Types::LEX_ARR_ON) {
			gl();
			if (type != Types::LEX_NUM) throw "Неверный размер массива";
			Lex  l = lex;
			gl();
			for (int i = 0; i < poliz.size(); i++) {
				if (sc.TID[poliz[i].get_val()].get_declare()) throw "Повторно обьявленная переменная" + sc.TID[stack[i]].get_name();
				sc.TID[poliz[i].get_val()].put_type(Types::LEX_INT);
				sc.TID[poliz[i].get_val()].set_declare();
				sc.TID[poliz[i].get_val()].set_is_arr();
				sc.TID[poliz[i].get_val()].arr = std::vector<int>(l.get_val(), 0);
			}
			if (type != Types::LEX_ARR_OFF) throw lex;
			gl();

		}
		else 
		for (int i = 0; i < poliz.size(); i++) {
			if (sc.TID[poliz[i].get_val()].get_declare()) throw "Повторно обьявленная переменная" + sc.TID[stack[i]].get_name();
			sc.TID[poliz[i].get_val()].put_type(Types::LEX_INT);
			sc.TID[poliz[i].get_val()].set_declare();
		}
	}
	else {
		gl();
		if (type == Types::LEX_ARR_ON) {
			gl();
			if (type != Types::LEX_NUM) throw "Неверный размер массива";
			Lex  l = lex;
			gl();
			for (int i = 0; i < poliz.size(); i++) {
				if (sc.TID[poliz[i].get_val()].get_declare()) throw "Повторно обьявленная переменная" + sc.TID[stack[i]].get_name();
				sc.TID[poliz[i].get_val()].put_type(Types::LEX_BOOL);
				sc.TID[poliz[i].get_val()].set_declare();
				sc.TID[poliz[i].get_val()].set_is_arr();
				sc.TID[poliz[i].get_val()].arr = std::vector<int>(l.get_val(), 0);
			}
			if (type != Types::LEX_ARR_OFF) throw lex;
			gl();

		}
		else
		for (int i = 0; i < poliz.size(); i++) {
			if (sc.TID[poliz[i].get_val()].get_declare()) throw "Повторно обьявленная переменная" + sc.TID[stack[i]].get_name();
			sc.TID[poliz[i].get_val()].put_type(Types::LEX_BOOL);
			sc.TID[poliz[i].get_val()].set_declare();
		}
	}
	poliz.clear();
}

void Translate::I1() {
	I2();
	while (type == Types::LEX_COMMA) {
		gl();
		I2();
	}
}

void Translate::I() {
	I2();
	if (type == Types::LEX_ARR_ON) {
		gl();
		E();
		if (type != Types::LEX_ARR_OFF) throw lex;
		gl();
		poliz.push_back(Types::LEX_ARR_OFF);
	}
}

void Translate::I2() {
	if (type != Types::LEX_ID) throw lex;
	poliz.push_back(lex);
	gl();
}

void Translate::B() {
	if (type != Types::LEX_BEGIN) throw lex;
	gl();
	S1();
	if (type != Types::LEX_END) throw lex;

	gl();
}

void Translate::S1() {
	S();
	while (type == Types::LEX_SEMICOLON) {
		poliz.push_back(Types::LEX_SEMICOLON);

		gl();
		S();
	}
}

void Translate::S() {
	if (type == Types::LEX_IF) {

		gl();
		E();
		int i = poliz.size();
		poliz.push_back(Types::POLIZ_LABEL);
		poliz.push_back(Types::POLIZ_FGO);
		if (type != Types::LEX_THEN) throw lex;
		gl();
		S();
		int j = poliz.size();
		poliz.push_back(Types::POLIZ_LABEL);
		poliz.push_back(Types::POLIZ_GO);
		if (type == Types::LEX_ELSE) {
			poliz[i].set_val( poliz.size());
			gl();
			S();
			poliz[j].set_val(poliz.size()+1);

		}
		
	}
	else if (type == Types::LEX_WHILE) {
		int i = poliz.size();
		gl();
		E();
		poliz.push_back(Types::POLIZ_LABEL);
		int j = poliz.size();
		poliz.push_back(Types::POLIZ_FGO);
		if (type != Types::LEX_DO) throw lex;
		gl();
		S();
		poliz.push_back(Types::POLIZ_LABEL);
		poliz.back().set_val(i);
		poliz.push_back(Types::POLIZ_GO);
		i = poliz.size();
		poliz[j-1].set_val(poliz.size() + 1);
	}
	else if (type == Types::LEX_BEGIN) {
		B();
	}
	else if (type == Types::LEX_READ) {
		gl();
		if (type != Types::LEX_STAPLES_ON) throw lex;
		gl();
		I2(); if (type == Types::LEX_ARR_ON) {
			gl();
			E();
			if (type != Types::LEX_ARR_OFF) throw lex;
			gl();
			poliz.push_back(Types::LEX_ARR_ON);
		}
		if (type != Types::LEX_STAPLES_OFF) throw lex;
		gl();
		poliz.push_back(Types::LEX_READ);
	}
	else if (type == Types::LEX_WRITE) {
		gl();
		if (type != Types::LEX_STAPLES_ON) throw lex;
		gl();
		E();
		if (type != Types::LEX_STAPLES_OFF) throw lex;
		gl();
		poliz.push_back(Types::LEX_WRITE);
	}
	else {
		I2();
		if (type == Types::LEX_ARR_ON) {
			gl();
			E();
			if (type != Types::LEX_ARR_OFF) throw lex;
			gl();
			poliz.push_back(Types::LEX_ARR_ON);
		}
		if (type != Types::LEX_ASSIGN) throw lex;
		gl();
		E();
		push(Types::LEX_ASSIGN);

	}
	for (int i = 0; i < signs.size(); i++) {
		poliz.push_back(signs.back());
		signs.pop_back();
	}

}

void Translate::E() {
	E1();
	if (type == Types::LEX_EQ || type == Types::LEX_L || type == Types::LEX_G || type == Types::LEX_LE ||
		type == Types::LEX_GE || type == Types::LEX_NEQ) {
		Types t = type;
		gl();
		E1();
		push(t);
	}
	
}

void Translate::E1() {
	T();
	while (type == Types::LEX_PLUS || type == Types::LEX_MINUS || type == Types::LEX_OR) {
		Types t = type;
		gl();
		T();
		push(t);
	}
}

void Translate::T() {
	F();
	while (type == Types::LEX_MUL || type == Types::LEX_DIV || type == Types::LEX_AND) {
		Types t = type;
		gl();
		F();
		push(t);
	}
}

void Translate::F() {
	if (type == Types::LEX_NOT) {
		gl();
		F();
		poliz.push_back(Types::LEX_NOT);
	}
	else if (type == Types::LEX_STAPLES_ON) {
		signs.push_back(Types::LEX_STAPLES_ON);
		gl();
		E();
		if (type != Types::LEX_STAPLES_OFF) throw lex;
		gl();
		straples();
	}
	else if (type == Types::LEX_ID) {
		I();
	}
	else if (type == Types::LEX_TRUE || type == Types::LEX_FALSE || type == Types::LEX_NUM) {
		poliz.push_back(lex);
		gl();
	}
	else throw lex;
}

void Translate::straples() {
	while (signs.back() != Types::LEX_STAPLES_ON) {
		poliz.push_back(signs.back());
		signs.pop_back();
	}
	signs.pop_back();
}

void Translate::push(Types t) {
	if (signs.empty()) {
		poliz.push_back(t);
	}
	else if (cmp(t, signs.back())) {
		signs.push_back(t);
	}
	else {
		while (!signs.empty()&&!cmp(t, signs.back()) ) {
			poliz.push_back(signs.back());
			signs.pop_back();
		}
		signs.push_back(t);
	}
}

bool Translate::cmp(Types t, Types d) {
	switch (t) {
	case Types::LEX_MUL:
	case Types::LEX_DIV:
	case Types::LEX_AND:
		return true;
	
	case Types::LEX_PLUS:
	case Types::LEX_MINUS:
	case Types::LEX_OR:
		if (d == Types::LEX_MUL || d == Types::LEX_DIV || d == Types::LEX_AND)
			return false;
	}
	return true;
}



void Translate::print_TID() {
	for (int i = 0; i < sc.TID.size(); i++) {
		std::cout << sc.TID[i].get_name() << " " << sc.TID[i].get_type() << " " << sc.TID[i].get_declare() << "\n";
		if (sc.TID[i].get_is_arr())
			std::cout << "WOW   ";
	}

}
