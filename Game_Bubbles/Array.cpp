#include "Array.h"
#include "Cell.h"
using std::cout;
namespace Game {
	template class Array<int>;
	template class Array<Array<int>>;
	template class Array<Cell*>;
	template class Array<Array<Cell*>>;

	template<typename S>
	Array<S>::Array(int x, S val) : len(x) {
		for (; len > maxlen; maxlen *= 2) {}
		a = new S[maxlen]{};
		for (int i = 0; i < len; i++)
			a[i] = val;
	};
	template<typename S>
	Array<S>::Array() : len(0) {
		a = new S[maxlen]{};
	}
	template<typename S>
	Array<S>::Array(const Array& other) : len(other.size()) {
		for (; len > maxlen; maxlen *= 2) {}
		a = new S[maxlen]{};
		for (int i = 0; i < len; i++)
			a[i] = other[i];
	}

	template<typename S>
	Array<S>& Array<S>::operator=(const Array& other) {
		if (this == &other) return *this;
		delete[]a;
		len = other.size();
		maxlen = 2;
		for (; len > maxlen; maxlen *= 2) {}
		a = new S[maxlen]{};
		for (int i = 0; i < len; i++)
			a[i] = other[i];
		return *this;
	}

	template<typename S>
	S& Array<S>::operator[](int num) const {
		return a[num];
	}
	template<typename S>
	int Array<S>::resize(int new_len, S val) {
		if (new_len <= maxlen) {
			for (int i = len; i < new_len; i++) {
				a[i] = val;
			}
			len = new_len;
		}
		else {
			int i;
			for (; new_len > maxlen; maxlen *= 2) {}
			S* t = new S[maxlen]{};
			for (i = 0; i < len; i++)
				t[i] = a[i];
			for (; i < new_len; i++)
				t[i] = val;
			delete[]a;
			a = t;
			len = new_len;
		}
		return len;
	}
	template<typename S>
	int Array<S>::size() const {
		return len;
	}
	template<typename S>
	void Array<S>::clear() {
		S s = S{};
		for (int i = 0; i < len; i++) {
			a[i] = s;
		}
	}
	template<typename S>
	void Array<S>::push_back(S val) {
		if (len == maxlen) {
			resize(len + 1);
			a[len - 1] = val;
		}
		else {
			len++;
			a[len - 1] = val;
		}
	}
	template<typename S>
	S Array<S>::pop_back() {
		if (len == 0) {
			fprintf(stderr, "GG");
			return S{};
		}
		else {
			len--;
			return a[len];
		}

	}
	template<typename S>
	S& Array<S>::front() const {
		return a[0];
	}
	template<typename S>
	S& Array<S>::back() const {
		return a[len - 1];
	}
	template<typename S>
	Array<S>::~Array() {
		delete[]a;
	}
}
