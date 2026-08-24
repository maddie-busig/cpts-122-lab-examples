#include "List.hpp"

List::List(const List& other) : head(nullptr) {
	deepCopy(other);
}

void List::deepCopy(const List& other) {
	Node* cur = other.head;

	Node** link = &head;

	while (cur != nullptr) {
		Node* newNode = new Node(cur->value);
		*link = newNode;

		link = &newNode->next;
		cur = cur->next;
	}
}

void List::clear() {
	Node* cur = head;

	while (cur != nullptr) {
		Node* next = cur->next;
		delete cur;
		cur = next;
	}

	head = nullptr;
}

void List::insertFront(int value) {
	Node* newNode = new Node(value);

	newNode->next = head;
	head = newNode;
}

List& List::operator=(const List& rhs) {
	if (&rhs != this) {
		clear();
		deepCopy(rhs);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& stream, const List& rhs) {
	List::Node* cur = rhs.head;

	if (rhs.head == nullptr) {
		stream << "<empty>";
	}

	while (cur != nullptr) {
		stream << cur->value << " ";
		cur = cur->next;
	}

	return stream;
}

