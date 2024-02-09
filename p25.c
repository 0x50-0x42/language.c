#include<stdio.h>
#define MAXLINE 1000

int getLine(char[], int);
void copy(char[], char[]);

int main(void) {
	char line[MAXLINE], longest[MAXLINE];

	int len, max = 0;


	while((len = getLine(line, MAXLINE)) > 0) {

		if(len > max) {
			max = len;
			copy(longest, line);
		}
	}

	printf("Longest string: %s\n", longest);
	printf("\nLength: %d\n", max);

	return 0;
}

int getLine(char line[], int maxline) {

	int c, idx = 0;

	while(((c = getchar()) != EOF) && (c != '\n') && (idx != maxline - 1)) {
		line[idx++] = c;
	}
}

void copy(char to[], char from[]) {
	for(int i = 0; from[i] != '\0'; i++)
		to[i] = from[i];
}
