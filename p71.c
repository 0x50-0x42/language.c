/*
	improved version of p69.c
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

void _getline(char[], int);
void strindex(char[], char[]);

int main(void) {

	char s[MAXLEN], pattern[MAXLEN];

	printf("enter a string: ");
	_getline(s, MAXLEN);

	clearerr(stdin);

	printf("enter a pattern: ");
	_getline(pattern, MAXLEN);

	strindex(s, pattern);

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

void strindex(char s[], char pattern[]) {

	int count = 0;
	int len = strlen(pattern);

	for(int i = 0; s[i] != '\0'; i++) {
		for(int k = 0; s[i] == pattern[k] && s[i] != '\0'; k++, i++)
			count++;

		if(count == len) {
			while(s[i] != '\n' && i > 0)
				i--;
			if(s[i] == '\n')
				i++;

			while(s[i] != '\n' && s[i] != '\0') {
				printf("%c", s[i]);
				i++;
			}
			printf("\n");
		}

		count = 0;
	}
}
