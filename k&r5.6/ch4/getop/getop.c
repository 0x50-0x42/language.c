#include<ctype.h>

#define NUM '0'

int getch();
void ungetch(int);

int getop(char *operand) {

	int c;

	while((c = getch()) == ' ' || c == '\t' || c == '\n')
		;

	if(isdigit(c)) {
		*operand = c;

		operand++;

		while(isdigit(c = getch()))
			*operand++ = c;
		if(c == '.') {
			*operand = c;
			operand++;
			while(isdigit(c = getch()))
				*operand++ = c;

			*operand = '\0';

			ungetch(c);
		}

		ungetch(c);

		return NUM;
	}

	else
		return c;
}
