#include<stdio.h>

void _getline(char *s, int lim) {
	int c, idx = 0;

	while((c = getchar()) != EOF && idx < lim)
		s[idx++] = c;

	idx--;

	// remove trailing whitespaces, tabs and newlines
	while(s[idx] == ' ' || s[idx] == '\n' || s[idx] == '\t')
		idx--;

	s[idx + 1] = '\0';
}
