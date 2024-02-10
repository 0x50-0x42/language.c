#include<stdio.h>
#define MAXLINE 1000

int getLine(char[]);
void entab(char[], int);

int main(void) {

	char line[MAXLINE];

	int len;

	len = getLine(line);

	entab(line, len);

	return 0;
}

int getLine(char[]) {

	int c, idx = 0;

	while((c = getchar()) != EOF && c != '\n' && idx != MAXLINE - 1)
		line[idx++] = c;

	if(idx == MAXLINE - 1) {
		line[idx] = '\0';
		line[idx - 1] = '\n';

		while((c = getchar()) != '\n')
			idx++;

		return idx;
	}

	else if(c == '\n')
		line[idx++] = c;

	line[idx] = '\0';

	return idx;
}

void entab(char line[], int len) {
}
