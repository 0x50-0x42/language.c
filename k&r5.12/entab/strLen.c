#include<stdio.h>

long unsigned strLen(char*string) {

	if(string == NULL)
		return 0;

	long unsigned chars = 0;

	while(*string != '\0') {
		chars++;
		string++;
	}

	return chars;
}
