#include<stdio.h>
#include<ctype.h>

char get_op(char s[]) {

	int idx = 0;

	// skip any leading whitespaces, newlines or tabs
	while((c = getch()) == ' ' || c == '\t' || c == '\n')
		;

	if(!isdigit(c) && c != '.')
		return c;

	if(isdigit(c)) {
		s[0] = c;
		s[1] = '\0';
	}

	while(isdigit((c = getch())))
		s[++idx] = c;
}
