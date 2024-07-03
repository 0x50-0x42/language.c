/*
	an example from K&R2:
		a function strindex() that prints the line that contains a particular pattern;
*/

#include<stdio.h>

#define MAXLEN 1000

void strindex(char[], char[]);
void getLine(char[]);

int main(void) {

	char s[MAXLEN], pattern[MAXLEN];

	printf("enter some string: ");
	getLine(s);

	printf("enter pattern: ");
	getLine(pattern);

	strindex(s, pattern);

	return 0;
}

void getLine(char s[]) {
	int c, idx = 0;

	while((c = getchar()) != 27)
		s[idx++] = c;
}

void strindex(char s[], char pattern[]) {
}
