#include<stdio.h>

int _getline(char *s, int lim) {
	int idx = 0, c;

	while((c = getchar()) != EOF && idx < lim)
		s[idx++] = c;

	s[idx] = '\0';

	return idx;
}
