#include<stdio.h>

int _getline(char *string, int lim) {

	char *base = string;
	
	int c;

	while((c = getchar()) != EOF && (string - base) < lim - 1)
		*string++ = c;

	string--;

	while(*string == ' ' || *string == '\t' || *string == '\n')
		string--;

	*++string = '\0';

	return (string - base);
}
