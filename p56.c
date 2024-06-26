/*
	atoi() that converts a string of digits into a number, also checks for whitespaces and sign
*/

#include<stdio.h>
#include<ctype.h>

int _atoi(char[]);

int main(void) {
	char s[100];

	printf("Enter a string: ");

	int c, idx = 0, result;

	while((c = getchar()) != '\n')
		s[idx++] = c;

	result = _atoi(s);

	printf("%s converted to number is: %d\n", s, result);

	return 0;
}

int _atoi(char s[]) {

	int i, n, sign;

	for(i = 0; isspace(s[i]); i++) // skip whitespace if any(in the beginning of the number)
		;

	sign = (s[i] == '-') ? -1 : 1; // take the sign if any

	if(s[i] == '-' || s[i] == '+') // after taking the sign, move forward
		i++;

	for(n = 0; isdigit(s[i]); i++) // now convert the string into a number
		n = n * 10 + (s[i] - '0');

	return sign * n;
}
