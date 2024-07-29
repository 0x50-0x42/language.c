#include<stdio.h>
#include<ctype.h>

#define NUM '0'

int getch();
void ungetch(int);

int get_op(char s[]) {
	int c, idx = 0;

	// skip whitespaces, tabs or newlines
	while((c = getch()) == ' ' || c == '\t' || c == '\n')
		;

	if(isdigit(c)) {
		s[idx++] = c;
		s[idx++] = '\0';
	}

	if(!isdigit(c) || c != '.')
		return c;

	while(isdigit((c = getch())))
		s[idx++] = c;

	if(c == '.') {
		s[idx++] = c;
		while(isdigit((c = getch())))
			s[idx++] = c;
	}

	s[idx] = '\0';

	if(c != EOF)
		ungetch(c); // push back c into input

	return NUM;
}
