/*
	write a function expand(s1, s2) that expands shorthand notations
	like a-z in the string s1 into the equivalent complete list abc...xyz
	in s2; allow for letters of either case and digits, and be prepared
	to handle cases like a-b-c and a-z0-9 and -a-z arrange that a leading
	or trailing - is taken literally;
*/

#include<stdio.h>
#include<ctype.h>

#define MAXLEN 1000

void expand(char[], char[]);

int main(void) {

	char s1[MAXLEN] = "", s2[MAXLEN] = "";
	
	int c, idx = 0;

	while((c = getchar()) != 27) // take input until user presses ESC key
		s1[idx++] = c;

	return 0;
}

void expand(char s1[], char s2[]) {
	int i;

	for(i = 0; isspace(s1[i]); i++); // skip whitespaces(if any) before s1

	for( ; s1[i] != '\0'; i++) {
	}
}
