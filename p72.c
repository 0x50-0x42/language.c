/*
	an example from K&R2:
		atof(s): converts the string s to its double-precision
		floating-point equivalent;
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLEN 1000

float _atof(char[]);
void _getline(char[], int);

int main(void) {

	char s[MAXLEN];

	printf("enter a floating point number: ");
	_getline(s, MAXLEN);

	printf("number is: %f\n", _atof(s));

	return 0;
}

void _getline(char s[], int lim) {

	int c, idx = 0, len;

	while(((c = getchar()) != EOF) && lim > 0) {
		s[idx++] = c;
		--lim;
	}

	s[idx] = '\0';

	idx--;

	len = strlen(s) - 1;

	// remove any trailing newlines, tabs and whitespaces
	while(s[idx] == '\n' || s[idx] == '\t' || s[idx] == ' ')
		idx--;

	if(idx != len)
		s[idx + 1] = '\0';
}

float _atof(char s[]) {

	int num1 = 0, num2 = 0, i = 0;

	float mul = 1, result;

	int sign = 1;

	while(isspace(s[i])) // ignore leading whitespaces
		i++;

	if(s[i] == '-') { // sign handling
		sign = -1;
		i++;
	}

	while(s[i] != '.' && s[i] != '\0') { // handling the integral part
		num1 = num1 * 10 + (s[i] - '0');
		i++;
	}

	if(s[i] == '.')
		i++;

	while(s[i] != '\0') { // now handling the decimal part
		num2 = num2 * 10 + (s[i] - '0');
		mul *= 0.1;
		i++;
	}

	result = sign * (num1 + num2 * mul);

	return result;
}
