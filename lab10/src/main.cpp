#include "Stack.hpp"

#include <iostream>

int main() {
	Stack<int> stack;

	for (int x : { 1, 2, 3, 4, 5 }) {
		bool r = stack.push(x);

		int sx;
		r &= stack.peek(sx);

		if (r == false || sx != x) {
			std::cerr << "Bad push" << std::endl;
			return -1;
		}
	}

	for (int x : { 5, 4, 3, 2, 1 }) {
		int sx;
		bool r = stack.pop(sx);

		if (r == false || sx != x) {
			std::cerr << "Bad pop" << std::endl;
			return -1;
		}
	}

	std::cout << "TESTS OK" << std::endl;

	return 0;
}

