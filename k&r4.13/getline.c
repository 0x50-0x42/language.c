#include<stdio.h>

int _getline(char s[], int lim) {
	int idx = 0, c;

	while((c = getchar()) != EOF && idx != lim)
		s[idx++] = c;

	idx--;

	// remove trailing whitespaces, newlines and tabs
	while(s[idx] == ' ' || s[idx] == '\n' || s[idx] == '\t')
		idx--;
	s[idx + 1] = '\0';

	idx++;

	return idx;
}
