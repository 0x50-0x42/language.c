#include<ctype.h>

double _atof(char *s) {

	int sign = 1;

	while(isspace(*s))
		s++;

	if(*s == '-') {
		sign *= -1;
		s++;
	}

	int num1 = 0, num2 = 0;

	double mul = 1;

	// convert the integral part to number
	while(*s != '.')
		num1 = num1 * 10 + (*s++ - '0');
	*s++;

	// convert the decimal part to number
	while(*s) {
		num2 = num2 * 10 + (*s++ - '0');
		mul *= 0.1;
	}

	return sign * (num1 + num2 * mul);
}
