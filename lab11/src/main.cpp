#include "algorithms.hpp"

#include <iostream>

int main(void) {
	int arr[] = {8, 3, 1, 5, 9, 2, 3, 4, 11, 57};
	size_t arr_size = sizeof(arr) / sizeof(*arr);

	for (int x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	merge_sort(arr, arr_size);

	for (int x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	return 0;
}

