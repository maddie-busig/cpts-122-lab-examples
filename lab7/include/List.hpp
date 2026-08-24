#pragma once

#include <iostream>

class List {
private:
	struct Node {
		Node(int value_) : value(value_) {}

		Node* next = nullptr;
		int value;
	};

	// Deep copies a list into the current list.
	// Prerequisites: this list must be empty
	void deepCopy(const List& other);

public:
	List() : head(nullptr) { }

	// Deep copy
	List(const List& other);

	List& operator=(const List& rhs);

	void insertFront(int value);

	void clear();

	friend std::ostream& operator<<(std::ostream& stream, const List& rhs);

private:
	Node* head;
};

