#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct Node {
	struct Node* p_next;
	struct Node* p_prev;
	int value;
} Node;

void insertAtFront(Node** p_list, int value);
void insertInOrder(Node** p_list, int value);
bool deleteFirst(Node** p_list, int value);
bool editFirst(Node* p_head, int oldValue, int newValue);
void printList(Node* list);

#endif // LINKED_LIST_H

