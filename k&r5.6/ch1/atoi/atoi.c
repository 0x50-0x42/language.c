int _atoi(char *s) {

	int num = 0;
	while(*s != '\0')
		num = num * 10 + (*s++ - '0');

	return num;
}
