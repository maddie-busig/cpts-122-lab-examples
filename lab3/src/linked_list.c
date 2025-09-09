#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

Node* makeNode(int value) {
	Node* newNode = malloc(sizeof(Node));

	newNode->p_next = NULL;
	newNode->p_prev = NULL;
	newNode->value = value;

	return newNode;
}

void insertAtFront(Node** p_list, int value) {
	Node* newNode = makeNode(value);

	Node* p_head = *p_list;

	newNode->p_next = p_head;
	
	if (p_head != NULL) {
		p_head->p_prev = newNode;
	}

	*p_list = newNode;
}

void printList(Node* list) {
	Node* p_cur = list;

	printf("list : ");

	while (p_cur != NULL) {
		printf("%d ", p_cur->value);
		p_cur = p_cur->p_next;
	}

	printf("\n");
}

void insertInOrder(Node** p_list, int value) {
	Node* newNode = makeNode(value);

	Node* p_prev = NULL;
	Node* p_cur = *p_list;

	while (p_cur != NULL && p_cur->value < value) {
		p_prev = p_cur;
		p_cur = p_cur->p_next;
	}

	newNode->p_next = p_cur;
	newNode->p_prev = p_prev;

	if (p_prev != NULL) {
		p_prev->p_next = newNode;
	} else {
		*p_list = newNode;
	}

	if (p_cur != NULL) {
		p_cur->p_prev = newNode;
	}
}

// Also, could prompt the user for the new value instead of passing it.
bool editFirst(Node* p_head, int oldValue, int newValue) {
	Node* p_cur = p_head;

	while (p_cur != NULL && p_cur->value != oldValue) {
		p_cur = p_cur->p_next;
	}

	if (p_cur != NULL) {
		// Set the new value. Set contact struct in actual lab
		p_cur->value = newValue;
	}

	return p_cur != NULL;
}

