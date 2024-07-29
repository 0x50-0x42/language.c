#include<stdio.h>
#include<ctype.h>

#define NUM '0'

int getch();
void ungetch(int);

extern int eof;

int get_op(char s[]) {

	int c, idx = 0;

	while((c = getch()) == ' ' || c == '\t' || c == '\n')
		;

	if(isdigit(c)) {
		s[idx++] = c;
		s[idx] = '\0';
	}

	if(!isdigit(c) && c != '.' && c != EOF)
		return c;

	while(isdigit((c = getch())))
		s[idx++] = c;

	if(c == '.') {
		s[idx++] = c;

		while(isdigit((c = getch())))
			s[idx++] = c;
	}

	ungetch(c); // push-back c(be it non-digit or EOF) into input

	if(eof)
		return EOF;

	return NUM;
}
