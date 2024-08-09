#include<stdio.h>
#include<ctype.h>

#define NUM '0'
#define SIN '$'
#define COS '!'
#define EXP '#'
#define VAR '@'
#define INV '~'

extern int i, sign, var;

int parse(char s[], char operand[], int len) {

	int idx = 0;

	while(s[i] != '\0') {

		// CHECK IF s[i] IS A DIGIT
		if(isdigit(s[i])) {
			while(isdigit(s[i])) // store the digit and the digits following it(if any)
				operand[idx++] = s[i++];
			if(s[i] == '.') // store the '.'
				operand[idx++] = s[i++];

			while(isdigit(s[i])) // continue storing digits after '.'(if any)
				operand[idx++] = s[i++];

			operand[idx] = '\0';

			return NUM; // we have got a number
		}

		// s[i] IS NOT A DIGIT
		if(!isdigit(s[i])) {

			// CHECK IF s[i] IS '-'
			if(s[i] == '-') {
				// CHECK IF i IS THE LAST INDEX
				if((i + 1) != len) {
					if(isdigit(s[i + 1])) { // CHECK IF s[i + 1] IS A DIGIT
						sign = -1; // negative number
						i++;
						while(isdigit(s[i]))
							operand[idx++] = s[i++];
						if(s[i] == '.')
							operand[idx++] = s[i++];
						while(isdigit(s[i]))
							operand[idx++] = s[i++];

						operand[idx] = '\0';

						return NUM;
					}

					return s[i++]; // IF s[i] IS NOT A DIGIT
				}

				return s[i++]; // IF i + 1 IS len
			}

			// IF s[i] IS AN UPPERCASE ALPHABET(i.e. A VARIABLE)
			if(s[i] >= 'A' && s[i] <= 'Z') {
				var = s[i++];
				return VAR;
			}

			// CHECKING FOR MATHEMATICAL FUNCTIONS AND ALSO COMMANDS
			if(s[i] == 's') {
				if(s[i + 1] == 'i') {
					if(s[i + 2] == 'n') {
						i += 3;
						return SIN;
					}
				}

				return s[i++];
			}

			if(s[i] == 'e') {
				if(s[i + 1] == 'x') {
					if(s[i + 2] == 'p') {
						i += 3;
						return EXP;
					}
				}

				return INV;
			}

			if(s[i] == 'c') {
				if(s[i + 1] == 'o') {
					if(s[i + 2] == 's') {
						i += 3;
						return COS;
					}
				}

				return s[i++];
			}

			return s[i++];
		}

	}

	return EOF;
}
