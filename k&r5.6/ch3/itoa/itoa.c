void reverse(char*);

void itoa(int num, char *s) {

	int i = 0;

	if(num < 0) {
		*s = '-';
		num *= -1;
		i++;
	}

	while(num) {
		s[i++] = num % 10 + '0';
		num /= 10;
	}

	s[i] = '\0';

	reverse(s);
}
