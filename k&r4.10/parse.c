#include<stdio.h>
#include<ctype.h>

#define NUM '0'
#define SIN '$'
#define EXP '#'

extern int i, sign;

int parse(char s[], char operand[], int len) {

	int idx = 0;

	while(s[i] != '\0') {

		if(isdigit(s[i])) { // if s[i] is a digit
			operand[idx++] = s[i]; // store it as an operand
			i++;
			while(isdigit(s[i])) // and continue taking the rest of the digits(if any) that follow s[i]
				operand[idx++] = s[i++];
			if(s[i] == '.') { // if s[i] is a decimal point
				operand[idx++] = s[i++]; // store it in operand
				while(isdigit(s[i])) // continue taking the decimal part
					operand[idx++] = s[i++];
			}

			return NUM;
		}

		if(!isdigit(s[i])) { // is s[i] is not a digit
			if(s[i] == '-') { // if s[i] is the minus operator
				if((i + 1) != len) { // we check if incrementing i by 1 equals the length of the input string
					if(isdigit(s[i + 1])) { // check if there is any digit after the '-' operator
						sign = -1; // it's a negative number
						i++;
						while(isdigit(s[i])) // take the number as operand
							operand[idx++] = s[i++];
						if(s[i] == '.') { // if s[i] is a decimal point
							operand[idx++] = s[i++]; // store it in operand
							while(isdigit(s[i])) // continue taking the decimal part
								operand[idx++] = s[i++];
						}

						return NUM;
					}

					else {
						return s[i];
					}
				}

				else {
					return s[i];
				}
			}

			if(s[i] == 's' || s[i] == 'S') { // for sin
				int j = i;
				j++;
				if(s[j] == 'i' || s[j] == 'I') {
					j++;
					if(s[j] == 'n' || s[j] == 'N') {
						i = j;
						return SIN;
					}
				}
			}
		}

		i++;
	}
}
