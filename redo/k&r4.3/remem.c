#include<stdio.h>

#define BUFSZ 100

char buffer[BUFSZ];

int bufp = -1;

char getch() {
	// either return what is in buffer or if buffer is emtpy, then call getchar()
	return bufp >=0 ? buffer[bufp--] : getchar();
}

void ungetch(char c) {
	if(bufp == BUFSZ) {
		puts("too many characters!");
		return;
	}

	buffer[++bufp] = c;
}
