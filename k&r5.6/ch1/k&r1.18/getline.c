#include<stdio.h>

int _getline(char *s, int lim) {

	int idx = 0, c;

	while((c = getchar()) != EOF && c != '\n' && idx < lim)
		s[idx++] = c;
	idx--;

	while(s[idx] == ' ' || s[idx] == '\t')
		idx--;
	s[idx + 1] = '\0';

	return c == EOF ? EOF : (idx + 1);
}
