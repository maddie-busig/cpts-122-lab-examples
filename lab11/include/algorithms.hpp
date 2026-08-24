#pragma once

#include <cstddef>

namespace detail {

// begin/end must be pointers to sequential memory
template <typename T>
void merge_sort(T* begin, T* end, T* work_begin, T* work_end) {
	// If there is only one element, nothing to sort, base case
	if (begin == end - 1) {
		return;
	}

	T* mid = begin + (end - begin) / 2;
	T* work_mid = work_begin + (work_end - work_begin) / 2;

	// Sort both of the sub arrays (end is the element after end of array)
	merge_sort(begin, mid, work_begin, work_mid);
	merge_sort(mid, end, work_mid, work_end);

	T* cur_left = begin;
	T* cur_right = mid;
	T* cur_work = work_begin;

	// While there is still elements in both sub arrays
	while (cur_left != mid && cur_right != end) {
		// Copy the smallest element into the working array
		if (*cur_left < *cur_right) {
			*cur_work = *cur_left;
			++cur_left;
		} else {
			*cur_work = *cur_right;
			++cur_right;
		}

		++cur_work;
	}

	// Copy whatever is left of both the sub arrays
	for ( ; cur_left != mid; ++cur_left) { *cur_work = *cur_left; }
	for ( ; cur_right != end; ++cur_right) { *cur_work = *cur_right; }

	// Copy from the working array back into the original array
	T* cur = begin;
	cur_work = work_begin;

	while (cur_work != work_end) {
		*cur = *cur_work;

		++cur;
		++cur_work;
	}
}

} // namespace detail

template <typename T>
void merge_sort(T* array, size_t size) {
	T* working_array = new T[size];

	detail::merge_sort(array, array + size, working_array, working_array + size);

	delete[] working_array;
}

