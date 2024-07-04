/*
	improved version of p69.c
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

void _getline(char[], int);
int strindex(char[], char[]);

int main(void) {

	char s[MAXLEN], pattern[MAXLEN];

	printf("enter a string: ");
	_getline(s, MAXLEN);

	printf("enter a pattern: ");
	_getline(pattern, MAXLEN);
	return 0;
}

void _getline(char s[], int lim) {

	int c, idx = 0, len;

	while(((c = getchar()) != EOF) && lim > 0) {
		s[idx++] = c;
		--lim;
	}

	s[idx] = '\0';

	len = strlen(s);

	// remove trailing newlines, tabs and whitespaces

	idx--;

	while(s[idx] == '\n' || s[idx] == '\t' || s[idx] == ' ')
		idx--;

	if(idx != len)
		s[idx + 1] = '\0';
}

int strindex(char s[], char pattern[]) {

	for(int i = 0; s[i] != '\0'; i++) {
	}

	return -1;
}
