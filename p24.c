#include<stdio.h>
#define MAXLINE 1000

int getLine(char[], int);
void copy(char[], char[]);

int main(void) {

	int len;

	char line[MAXLINE];
	char longest[MAXLINE];

	int max=0;

	while((len=getLine(line, MAXLINE)) > 0) {

		if(len > max) {
			max = len;
			copy(longest, line);
		}
	}

	printf("Longest string: %s\n", longest);

	return 0;
}

int getLine(char line[], int maxline) {
	int idx = 0, c;

	while(((c = getchar()) != EOF) && (idx < maxline - 1) && (c != '\n')) {
		line[idx++] = c;
	}

	if(c == '\n')
		line[idx++] = c;

	line[idx] = '\0';

	return idx;
}

void copy(char to[], char from[]) {
	for(int i = 0; from[i] != '\0'; i++)
		to[i] = from[i];
}
