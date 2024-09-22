#include<stdio.h>

int _getline(char *s, int lim) {
	int c;

	char *base = s;
	
	while((c = getchar()) != EOF && (s - base) < lim)
		*s++ = c == '\n' ? '\0' : c; // instead of putting a newline, put a null character at the end
	s--;

	while(*s == ' ' || *s == '\t' || *s == '\n')
		s--;
	*++s = '\0';

	return (s - base);
}
