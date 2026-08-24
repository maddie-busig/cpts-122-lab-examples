#include "List.hpp"

#include <iostream>

int main() {
	List l1;

	l1.insertFront(5);
	l1.insertFront(4);
	l1.insertFront(3);

	std::cout << "L1: " << l1 << std::endl;

	List l2(l1);
	List l3;

	std::cout << "L2: " << l2 << std::endl;
	std::cout << "L3: " << l3 << std::endl;

	l3 = l1;

	std::cout << "L3: " << l3 << std::endl;
	
	l1.clear();
	l1.insertFront(3);
	l1.insertFront(2);

	std::cout << "L1: " << l1 << std::endl;
	std::cout << "L2: " << l2 << std::endl;
	std::cout << "L3: " << l3 << std::endl;

	return 0;
}

