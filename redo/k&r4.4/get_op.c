#include<stdio.h>
#include<ctype.h>

#define NUM '0'

extern int sign;

int getch();
void ungetch(int);

int get_op(char s[]) {
	
	int c, idx = 0;

	while((c = getch()) == ' ' || c == '\t' || c == '\n') // skip any whitespace, tab or newline
		;

	if(isdigit(c)) {
		s[0] = c;
		s[1] = '\0';
	}

	if(!isdigit(c) && c != '.') {
		if(c == '-') {
			int temp;
			if(isdigit((temp = getch()))) {
				s[idx] = temp;
				sign = -1;

				while(isdigit((temp = getch())) || temp == '.')
					s[++idx] = temp;
				if(temp != EOF)
					ungetch(temp);
				s[++idx] = '\0';

				return NUM;
			}

			else {
				if(temp != EOF)
					ungetch(temp);
			}
		}

		return c;
	}

	while(isdigit((c = getch())) || c == '.')
		s[++idx] = c;

	if(c != EOF)
		ungetch(c);
	s[++idx] = '\0';

	return NUM;
}
