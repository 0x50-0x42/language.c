#include<stdio.h>
#include<ctype.h>

int getch();
void ungetch(int);

int getword(char*s, int maxchar) {

	int c;
	while(isspace(c = getch()))
		;

	if(isalpha(c) && !isspace(c) && c != EOF) {
		*s++ = c;
		while(isalpha(c = getch()) && !isspace(c) && c != EOF)
			*s++ = c;

		if(c != EOF && isspace(c))
			ungetch(c);
		*s = '\0';

		return 0;
	}

	*s = '\0';

	return c;
}
