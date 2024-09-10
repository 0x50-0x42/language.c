double _atof(char *s) {

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

	return (num1 + num2 * mul);
}
