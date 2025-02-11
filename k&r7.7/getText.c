#include<stdio.h>

void getText(char *string, const int length) {
	int c;

	while((c = getchar()) != EOF)
		*string++ = c;

	*string = '\0';
}
