/*
	write a routine ungets(s) that will push back an entire string onto the input;
	should ungets() know about buf and bufp or should it just use ungetch()?

	ungets() should use ungetch() for storing a string; but the string will need to be
	stored in reverse order;
	since, ungets() is using ungetch(), so it neednot know about buffer and bufp
*/


#include<stdio.h>
#include<float.h>
#include<stdlib.h>

#define MAXLEN 1000
#define NUM '0'

int getch();
void ungetch(int);
void ungets(char[]);

int get_op(char[]);

int main(void) {

	int c, idx = 0;

	char str[MAXLEN];

	printf("enter a string: ");

	while((c = getch()) != EOF)
		str[idx++] = c;

	str[idx] = '\0';

	ungets(str);

	puts("String from the buffer: ");

	while((c = getch()) != '\0')
		printf("%c", c);

	return 0;
}
