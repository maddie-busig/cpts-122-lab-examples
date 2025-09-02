#include <string.h>
#include <stdbool.h>
#include <stdio.h>

char* my_strcat(char* dest, const char* src) {
	char* original_dest = dest;

	// Finding the end of the destination string
	while (*dest != '\0') {
		dest += 1;
	}

	// Copying the source string into the destination
	while (*src != '\0') {
		*dest = *src;
		++dest;
		++src;
	}

	// Need to copy a null terminator into the string
	*dest = '\0';

	return original_dest;
}

void reverse_recursive(char* p1, char* p2) {
	if (p2 <= p1) {
		// Base case, done
		return;
	} else {
		// Recursive step
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;

		reverse_recursive(p1 + 1, p2 - 1);
	}
}

void reverse(char* str) {
	char* first = str;
	char* last = str + strlen(str) - 1;

	reverse_recursive(first, last);
}

// Checks whether the string contains the given character
bool str_contains(const char* str, char c) {
	if (str == NULL) {
		return false;
	}

	while (*str != '\0') {
		if (*str == c) {
			return true;
		}

		++str;
	}

	return false;
}

char* my_strtok(char* str, const char* delims) {
	static char* next_token = NULL;

	// If we are processing a new string, set the new next token
	if (str != NULL) {
		next_token = str;
	}

	// next_token is set to NULL if we have reached the end of the string,
	// and there is no work to do
	if (next_token == NULL) {
		return NULL;
	}

	// Finding a pointer to the next delimiter or null character
	char* p_end = next_token;
	while (*p_end != '\0' && !str_contains(delims, *p_end)) {
		++p_end;
	}

	char* cur_token = next_token;
	next_token = p_end + 1;

	// If the string's null character was reached, we are done tokenizing
	// the string, and there is no more work to do. i.e. no next token
	if (*p_end == '\0') {
		next_token = NULL;
	} else {
		// Otherwise we need to replace the delimiter with a null char
		*p_end = '\0';
	}

	return cur_token;
}
