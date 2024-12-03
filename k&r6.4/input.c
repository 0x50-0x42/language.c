#include<stdio.h>

#define MAX 1000

int buff[MAX];
int bufp = -1;

int getch() {
	return bufp >= 0 ? buff[bufp--] : getchar();
}

void ungetch(int val) {
	if(bufp >= MAX) {
		puts("too many characters");
		return;
	}

	buff[++bufp] = val;
}
