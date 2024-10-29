#include<stdio.h>

int _getline(char *string, int lim) { // count the number of lines input by the user

	int c;

	char *base = string;

	while((c = getchar()) != '\n' && c != EOF && (string - base) < lim - 1)
		*string++ = c;

	if(c == EOF)
		return 0;

	string--;

	while(*string == ' ' || *string == '\t' || *string == '\n')
		string--;

	*++string = '\0';

	return (string - base);
}
