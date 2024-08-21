#include<stdio.h>

int _getline(char *s, int lim) {
	int idx = 0, c, counter = 0;

	while((c = getchar()) != EOF && idx < lim) {
		s[idx++] = c;
		counter++;
		if(c == '\n' || counter > 80) {
			s[idx] = '\0';
			return counter;
		}
	}

	return EOF;
}
