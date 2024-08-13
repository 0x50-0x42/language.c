void _itoa(int num, char s[], int idx) {
	if(!num) {
		s[idx] = '\0';
		return;
	}

	if(num < 0) {
		s[idx] = '-';
		num *= -1;
		idx++;
	}

	s[idx] = num % 10 + '0';
	_itoa(num / 10, s, idx + 1);
}
