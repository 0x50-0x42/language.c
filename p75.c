/*
	a very interesting mechanism that I found in K&R2's implementation of reverse Polish
	notation calculator;

	just look below
*/

// Here is a program that takes only numbers as input

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

int getch(void); // delivers the next input character to be considered
void ungetch(int); // remembers the characters put back on the input, so that subsequent calls to getch will return them before reading new input
void getInp(char[], int);

int main(void) {

	char s[MAXLEN];

	printf("enter a string: ");
	getInp(s, MAXLEN);

	printf("String: %s\n", s);

	return 0;
}
