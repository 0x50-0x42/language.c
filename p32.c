#include<stdio.h>

#define LENGTH 1000

#define COL 100  // after 100 columns of input, the program will break a line!

int getLine(char[]);

int main(void) {
	char line[LENGTH];

	int len;

	len = getLine(line);
	return 0;
}

int getLine(char line[]) {
	int c, idx = 0;

	while((c = getchar()) != EOF && c != '\n' && idx != LENGTH - 1) {
		line[idx++] = c;
	}

	if(idx == LENGTH - 1) {
	}
}
