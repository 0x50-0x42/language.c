#include<stdio.h>

#include "def.h"

char*base;

int main(void) {

	char string[SIZE];

	printf("enter a string:\n");

	int len = _getline(string, SIZE);

	base = string;

	char *str;

	while(*(str = split(string)) != '\0')
		printf("string: %s\n", str);
	return 0;
}
