#include <stdio.h>
#include <string.h>

#include "lab1.h"

int main(void) {
	char str1[32] = "Hello ";
	char str2[32] = "World";

	printf("%s\n", str1);

	my_strcat(str1, str2);

	printf("%s\n", str1);

	reverse(str1);

	printf("%s\n", str1);

	char tstr1[] = "Hello and welcome to CPT_S 122!";
	char tstr2[] = "Hello and welcome to CPT_S 122!";
	char delims[] = " ";
	char* curtok = NULL;

	printf("Tokenizing using strtok\n");

	curtok = strtok(tstr1, delims);
	while (curtok != NULL) {
		printf("%s\n", curtok);
		curtok = strtok(NULL, delims);
	}

	printf("Tokenizing using my_strtok\n");

	curtok = my_strtok(tstr2, delims);
	while (curtok != NULL) {
		printf("%s\n", curtok);
		curtok = my_strtok(NULL, delims);
	}

	return 0;
}

