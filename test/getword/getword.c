#include<stdio.h>
#include<ctype.h>

int getch();
void ungetch(int);

int getword(char*s, int maxchar) {

	int c = 0;

	while(isspace(c = getch()))
		;

	while(isalpha(c) || !isspace(c) && c != EOF) {
		*s++ = c;
		while(isalpha(c = getch()) || !isspace(c) && c != EOF)
			*s++ = c;
		if(c != EOF)
			ungetch(c);

		*s = '\0';

		return 1;
	}

	return c;
}
