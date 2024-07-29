#include<stdio.h>

int buf = '\0'; // replaced the array by an int variable

int getch() {
	int temp = buf;
	if(buf != '\0') {
		buf = '\0';
		return temp;
	}

	else
		return getchar();
}

void ungetch(int val) {
	if(buf != '\0') {
		puts("too many characters!");
		return;
	}

	buf = val;
}
