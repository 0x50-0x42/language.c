#include<stdio.h>

#include "def.h"

int main(void) {

	char *str = "Hello world"; // a pointer to string constant "Hello world"

	char string[SIZE];

	printf("Original string: %s\n", str);

	_strcpy(string, str); // copy str to string

	printf("Copied string: %s\n", string);

	return 0;
}
