#include<stdio.h>
#define MAXSIZE 1000

static int buff[MAXSIZE];
static int bufp = -1;


int getch() {
	return bufp >= 0 ? buff[bufp--] : getchar();
}

void ungetch(int val) {
}
