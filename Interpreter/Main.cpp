#include <iostream>
#include "Translate.h"

int main() {
	setlocale(LC_ALL, "Rus");

	Translate tr("qq.txt");
	try {
		if (tr.analize())
			std::cout << " Good";
	}
	catch (Lex l) {
		std::cout << l << " Fail";
	}
	catch (std::string s) {
		std::cout << s;
	}
	catch (const char* c) {
		std::cout << c;
	}

	return 0;
}