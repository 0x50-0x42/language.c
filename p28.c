#include<stdio.h>
#define MAXLINE 1000

int getLine(char[], int);
void reverse(char[], char[], int);

int main(void) {

	char line[MAXLINE], reversed[MAXLINE];

	int len = 0;

	while((len = getLine(line, MAXLINE)) > 0) {
		printf("\nString: %s\n", Length: %d\n", line, len);

		reverse(line, reversed, len);

		printf("\nReversed string: %s\n", Length: %d\n", reversed, len);
	}

	puts("\nNo lines entered!");

	return 0;
}

int getLine(char line[], int maxline) {

	int idx = 0, c;

	while((c = getchar()) != EOF && c != '\n' && idx != maxline - 1) {
		line[idx++] = c;
	}

	if(idx == maxline - 1) {
		line[idx] = '\0';
		line[idx - 1] = '\n';

		for(int i = idx - 2; i > idx - 3; i--)
			line[idx] = '.';

		while((c = getchar()) != '\n')
			idx++;

		return idx;
	}

	else if(c == '\n')
		line[idx++] = c;

	line[idx] = '\0';

	return idx;
}

void reverse(char line[], char reversed[]) {
}