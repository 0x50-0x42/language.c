int _atoi(char *s) {

	int sign = 1;
	if(*s == '-') {
		sign *= -1;
		s++;
	}


	int num = 0;
	while(*s != '\0')
		num = num * 10 + (*s++ - '0');

	return sign * num;
}
