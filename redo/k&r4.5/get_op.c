#include<stdio.h>
#include<ctype.h>

#define NUM '!'
#define SIN '@'
#define EXP '#'

extern int sign;

int getch();
void ungetch(int);

int get_op(char s[]) { // the string s is only used to store operands, not operators!
	int c, idx = 0;

	// skip any whitespaces, newlines or tabs
	while((c = getch()) == ' ' || c == '\t' || c == '\n')
		;

	if(isdigit(c)) { // store c into the string if it's a digit
		s[0] = c;
		s[1] = '\0';
	}

	if(!isdigit(c) && c != '.') { // c is not a digit or the decimal point, that means it could be an operator
		if(c == '-') { // if c is particularly the minus symbol then
			int temp;
			if(isdigit((temp = getch()))) { // if there is a digit after the minus symbol then
				sign = -1; // set the sign to -1
				s[0] = temp; // store the parsed digit into the string
				while(isdigit((temp = getch())) || temp == '.') // as long as temp is a digit or if temp is a decimal point(once)
					s[++idx] = temp; // go on storing it into the string
				if(temp != EOF)
					ungetch(temp); // if temp is some other operator, then store it into the buffer(not the string)
				s[++idx] = '\0';

				return NUM;
			}

			else { // if temp is not a digit then
				if(temp != EOF)
					ungetch(temp); // store it into the buffer so that it can be fetched from the buffer the next time
			}
		}

		if(c == 's' || c == 'S') {
			int temp;
			if((temp = getch()) == 'i' || temp == 'I') {
				if((temp = getch()) == 'n' || temp == 'N')
					return SIN;
				else {
					if(temp != EOF)
						ungetch(temp);
				}
			}

			else {
				if(temp != EOF)
					ungetch(temp);
			}
		}

		if(c == 'e' || c == 'E') {
			int temp;
			if((temp = getch()) == 'x' || temp == 'X') {
				if((temp = getch()) == 'p' || temp == 'P')
					return EXP;
				else {
					if(temp != EOF)
						ungetch(temp);
				}
			}

			else {
				if(temp != EOF)
					ungetch(temp);
			}
		}

		return c;
	}

	// as long as c is a digit or a decimal point(only once), go on storing it into the string
	while(isdigit((c = getch())) || c == '.')
		s[++idx] = c;

	if(c != EOF)
		ungetch(c);

	s[++idx] = '\0';

	return NUM;
}
