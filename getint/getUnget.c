#include<stdio.h>
#include "def.h"

char buf[BUFSZ];
int bufp = -1;

int getch() {
	return bufp >= 0 ? buf[bufp--] : getchar();
}

void ungetch(int c) {
	if(bufp >= BUFSZ - 1) {
		puts("too many characters!");
		return;
	}

	buf[++bufp] = c;
}
