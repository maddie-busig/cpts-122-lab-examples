#ifndef LAB1_H
#define LAB1_H

char* my_strcat(char* dest, const char* src);

// `reverse_recursive` is only used internally by `reverse`,
// and should not be exposed to the user. So, we will not include
// a declaration for it here:
//
// void reverse_recursive(char* p1, char* p2);

void reverse(char* str);

char* my_strtok(char* str, const char* delim);

#endif

