#pragma once

#include <iostream>
using std::cout;
namespace Game {
	template<typename S>
	struct Array {
	private:
		S* a;
		int len;
		int maxlen = 2;
	public:

		Array(int x, S val = S{});
		Array();
		Array(const Array& other);

		Array& operator=(const Array& other);

		S& operator[](int num) const;

		int resize(int new_len, S val = S{});

		int size() const;
		void clear();
		void push_back(S val);
		S pop_back();
		S& front() const;
		S& back() const;
		~Array();

	};
}