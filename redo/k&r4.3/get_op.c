#include<stdio.h>
#include<ctype.h>

#define NUM '0'

char getch();
void ungetch(char);

extern int sign;

char get_op(char s[]) {

	int idx = 0;
	char c;

	// skip any whitespaces, newlines or tabs
	while((c = getch()) == ' ' || c == '\t' || c == '\n')
		;

	if(isdigit(c)) { // if c is a digit then store it
		s[0] = c;
		s[1] = '\0';
	}

	if(!isdigit(c) && c != '.') {// if c is neither a digit nor the decimal point
		if(c == '-') {
			int temp;
			if(isdigit((temp = getch()))) {
				sign = -1;
				s[0] = temp;
				while(isdigit((temp = getch())) || temp == '.') {
					s[++idx] = temp;
				}

				if(temp != EOF)
					ungetch(temp);
				s[++idx] = '\0';
				return NUM;
			}
			
			else { // if temp is not a digit then, instead of losing its value, we save it to the buffer
				ungetch(temp);
			}
		}

		return c;
	}

	while(isdigit((c = getch()))) // as long as c is a digit, keep on taking input
		s[++idx] = c;

	s[++idx] = '\0';

	if(c != EOF)
		ungetch(c); // store c in a buffer, so that next time when getch() is called, the input is fetched from the buffer

	return NUM;
}
