double _atof(char *s) {

	int sign = 1;

	if(*s == '-') {
		sign *= -1;
		s++;
	}

	int num1 = 0, num2 = 0;
	double mul = 1;

	while(*s != '.' && *s != '\0')
		num1 = num1 * 10 + *s++ - '0';

	if(*s == '.')
		s++;

	while(*s != '\0') {
		num2 = num2 * 10 + *s++ - '0';
		mul *= 0.1;
	}

	return (sign * (num1 + num2 * mul));
}
