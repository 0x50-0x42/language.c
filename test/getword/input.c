#include<stdio.h>

#define MAX 10000

static int buff[MAX];
static int bufp = -1;

int getch() {
	return bufp >= 0? buff[bufp--] : getchar();
}

void ungetch(int val) {
	if(bufp == MAX - 1) {
		puts("Too many input characters!");
		return;
	}

	buff[++bufp] = val;
}
