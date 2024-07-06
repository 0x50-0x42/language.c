/*
	extend atof() in p72.c to handle scientific notations of the form:
		123.45e-6
	where a floating-point number may be followed by e or E an an optionally signed component;
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLEN 1000

void _getline(char[], int);
double _atof(char[]);

int main(void) {

	char s[MAXLEN] = "";

	printf("enter a number: ");
	_getline(s, MAXLEN);

	double result = _atof(s);

	printf("Result: %lf\n", result);

	return 0;
}

void _getline(char s[], int lim) {
	
	int c, idx = 0;

	while(((c = getchar()) != EOF) && (lim > 0)) {
		s[idx++] = c;
		--lim;
	}

	s[idx] = '\0';

	idx--;

	// remove trailing newlines, tabs and whitespaces
	while(s[idx] == '\n' || s[idx] == '\t' || s[idx] == ' ')
		idx--;

	if(idx != (strlen(s) - 1))
		s[idx + 1] = '\0';
}

double _atof(char s[]) {
	int n1 = 0, n2 = 0;
	int i, sign = 1;

	double mul = 1, eMul = 1;
	int eNum = 0;;

	// handling leading whitespaces
	for(i = 0; isspace(s[i]); i++)
		;

	// take the sign
	if(s[i] == '-') {
		sign = -1;
		i++;
	}

	// handling the integral part
	while(s[i] != '.' && s[i] != '\0' && (s[i] != 'e' && s[i] != 'E')) {
		n1 = n1 * 10 + s[i] - '0';
		i++;
	}

	if(s[i] == '.')
		i++;

	// handling the decimal part
	while(s[i] != '\0' && s[i] != 'e' && s[i] != 'E') {
		n2 = n2 * 10 + s[i] - '0';
		mul *= 0.1;
		i++;
	}

	if(s[i] == 'e' || s[i] == 'E') { // if we have the exponent in the floating-point number
		if(s[i + 1] == '-') {
			i += 2;
			while(s[i] != '\0') {
				eNum = eNum * 10 + s[i] - '0';
				i++;
			}

			for(int j = 0; j < eNum; j++)
				eMul *= 0.1;
		}
		
		else {
			i++;
			while(s[i] != '\0') {
				eNum = eNum * 10 + s[i] - '0';
				i++;
			}

			for(int j = 0; j < eNum; j++)
				eMul *= 10.0;
		}
	}

	return (sign*((n1 + n2 * mul) * eMul));
}
