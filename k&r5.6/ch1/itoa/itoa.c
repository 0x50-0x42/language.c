void reverse(char*);

void itoa(int num, char *s) {

	int i = 0;

	while(num) {
		s[i++] = num % 10 + '0';
		num /= 10;
	}

	s[i] = '\0';

	reverse(s);
}
