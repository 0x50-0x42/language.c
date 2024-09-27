#include<stdio.h>

int _getline(char *s, int lim) {
	char *base = s;
	int c;

	while((c = getchar()) != EOF && (s - base) < lim)
		*s++ = c;

	s--;

	while(*s == ' ' || *s == '\t' || *s == '\n')
		s--;

	*++s = '\0';

	return (s - base);
}
