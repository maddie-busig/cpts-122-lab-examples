#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "linked_list.h"

int main(void) {
	Node* list = NULL;

	printList(list);
	insertAtFront(&list, 7);
	printList(list);
	insertAtFront(&list, 1);
	printList(list);
	insertAtFront(&list, 9);
	printList(list);
	insertAtFront(&list, 4);
	printList(list);
	insertAtFront(&list, 5);
	printList(list);

	Node* list2 = NULL;

	printList(list2);
	insertInOrder(&list2, 7);
	printList(list2);
	insertInOrder(&list2, 1);
	printList(list2);
	insertInOrder(&list2, 9);
	printList(list2);
	insertInOrder(&list2, 4);
	printList(list2);
	insertInOrder(&list2, 5);
	printList(list2);
	editFirst(list2, 5, 99);
	printList(list2);

	return 0;
}

