#include<stdio.h>

#define BUFSZ 100

extern int bufp;

extern char buffer[];

void ungetch(int val) {
	if(bufp >= BUFSZ) {
		puts("too many characters!");
		return;
	}

	buffer[++bufp] = val;
}
