#include<stdio.h>

int _getline(char* string, int lim) {
	int c;

	char *base = string;

	while((c = getchar()) != EOF && (string - base) < lim)
		*string++ = c;
	string--;

	while(*string == ' ' || *string == '\t' || *string == '\n')
		string--;
	*++string = '\0';

	return (string - base);
}
