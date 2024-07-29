#include<stdio.h>

#define BUFSZ 100

int buf[BUFSZ]; // to handle EOF

int bufp = -1;

int eof = 0; // flag for EOF

int getch() {
	return bufp >= 0 ? buf[bufp--] : getchar();
}

void ungetch(int c) {

	if(c == EOF) { // check before pushing back
		eof = 1; // set the eof flag
		return;
	}

	if(bufp >= BUFSZ) {
		puts("too many characters!");
		return;
	}

	buf[++bufp] = c;
}
