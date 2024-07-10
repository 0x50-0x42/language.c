#include<stdio.h>
#include<ctype.h>

int getch();
void ungetch(int);

void getInp(char s[], int lim) {

	int c, idx = 0;

	// ignore any leading whitespace and tabs
	while((c = getch()) == ' ' || c == '\t')
		;

	if(isdigit(c)) {
		s[idx++] = c;
		while(isdigit((c = getch()))) {
			s[idx++] = c;
		}

		s[idx] = '\0';
	}

	if(c != EOF)
		ungetch(c); // store into the buffer
}
