/*
	write a routine ungets(s) that will push back an entire string onto the input;
	should ungets() know about buf and bufp or should it just use ungetch()?

	storing the string by calling ungetch() in ungets() will store it in the buffer
	but when retrieving it using getch() it will be retrieved in reverse order(i.e. from the last character)
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
