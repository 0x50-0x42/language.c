#include<stdio.h>
#define BUFSZ 100

char buffer[BUFSZ];

int bufp = -1;

int getch() {
	return bufp >= 0 ? buffer[bufp--] : getchar();
}

void ungetch(int val) {
	if(bufp >= BUFSZ) {
		puts("too many characters!");
		return;
	}

	buffer[++bufp] = val;
}
