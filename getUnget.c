#include<stdio.h>

#define BUFFSIZE 100

int bufp;

char buffer[BUFFSIZE];

int getch(void) {

	// if the buffer contains anything then return this otherwise take user input
	return bufp > 0 ? buffer[--bufp] : getchar();
}

void ungetch(int c) { // push character back on input
	if(bufp >= BUFFSIZE)
		puts("too many characters!");
	else
		buffer[bufp++] = c;
	printf("Contents in buffer: %s\n", buffer);
}
