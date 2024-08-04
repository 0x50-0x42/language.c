#include<stdio.h>

int getLine(char s[], int lim) {
	int idx = 0, c;

	while((c = getchar()) != EOF)
		s[idx++] = c;

	idx--;

	// remove trailing whitespaces, tabs and newlines

	while(s[idx] == ' ' || s[idx] == '\t' || s[idx] == '\n')
		idx--;

	s[++idx] = '\0';

	return idx;
}
