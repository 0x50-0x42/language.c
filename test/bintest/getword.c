#include<stdio.h>
#include<ctype.h>

int getch();
void ungetch(int);


// naive getword()
int getword(char*string, int maxchar) {
	int c;

	// ignore whitespaces
	while(isspace(c = getch()))
		;

	if(isalnum(c)) {
		*string++ = c;
		while(isalnum(c = getch()))
			*string++ = c;

		ungetch(c);
	}

	*string = '\0';
	return c == EOF ? EOF : c;
}
