#include<stdio.h>
#include<ctype.h>

#define NUM '0'
#define SIN '!'
#define EXP '@'
#define POW '#'

extern int sign;

int getch();
void ungetch(int);

int get_op(char s[]) {

	int c, idx = 0;

	while((c = getch()) == ' ' || c == '\t' || c == '\n')
		;

	if(isdigit(c)) { // c is digit
		s[0] = c;
		s[1] = '\0';
	}

	if(!isdigit(c) && c != '.') { // c is neither a digit nor the decimal point
		if(c == '-') { // check if c is a negative sign
			int temp;
			if(isdigit((temp = getch()))) { // and if there is a digit after it
				sign = -1;
				s[idx] = temp;

				while(isdigit((temp = getch()))) // continue taking digits(the integral portion)
					s[++idx] = temp;
				if(temp == '.') { // if temp is a decimal point
					s[++idx] = temp;
					while(isdigit((temp = getch()))) // continue taking the decimal portion
						s[++idx] = temp;
				}

				if(temp != EOF)
					ungetch(temp); // remember this value so that it can be used as next input
				s[++idx] = '\0';

				return NUM;
			}

			else {
				if(temp != EOF)
					ungetch(temp);
			}
		}

		if(c == 's' || c == 'S') {
			if((c = getch()) == 'i' || c == 'I') {
				if((c = getch()) == 'n' || c == 'N') {
					return SIN;
				}

				else {
					if(c != EOF)
						ungetch(c);
				}
			}

			else {
				if(c != EOF)
					ungetch(c);
			}
		}

		if(c == 'e' || c == 'E') {
			if((c = getch()) == 'x' || c == 'X') {
				if((c = getch()) == 'p' || c == 'P') {
					return EXP;
				}

				else {
					if(c != EOF)
						ungetch(c);
				}
			}

			else {
				if(c != EOF)
					ungetch(c);
			}
		}

		return c;
	}

	while(isdigit((c = getch()))) // take the integral part
		s[++idx] = c;

	if(c == '.') {
		s[++idx] = c;
		while(isdigit((c = getch()))) // take the decimal part
			s[++idx] = c;
	}

	s[++idx] = '\0';

	return NUM;
}
