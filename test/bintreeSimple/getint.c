#include<stdio.h>
#include<ctype.h>

int getch();
void ungetch(int);

int getint() {
	int c;
	int num = 0;
	while(isspace(c = getch())) // skip whitespaces
		;

	if(isdigit(c)) {
		num = num * 10 + (c - '0');
		while(isdigit(c = getch()))
			num = num * 10 + (c - '0');
	}

	if(isspace(c))
		ungetch(c);

	if(c == EOF)
		return c;

	return num;
}
