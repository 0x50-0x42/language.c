#include<stdio.h>

#define BUFSZ 100

int bufp = -1;

char buffer[BUFSZ];

int getch() {
	return bufp >= 0 ? buffer[bufp--] : getchar();
}
