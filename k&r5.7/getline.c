#include<stdio.h>

int _getline(char *s, int lim) {
	int c, idx = 0;

	while((c = getchar()) != EOF && idx < lim)
		s[idx++] = c;
	idx--;

	while(s[idx] == ' ' || s[idx] == '\t' || s[idx] == '\n')
		idx--;

	s[idx + 1] = '\0';

	return idx;
}
