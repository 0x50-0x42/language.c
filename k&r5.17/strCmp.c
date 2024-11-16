int strCmp(void*s1, void*s2) {

	char*str1 = s1;
	char*str2 = s2;

	while(*str1 == *str2) {
		if(*str1 == '\0' || *str2 == '\0')
			return *str1 - *str2;
		str1++;
		str2++;
	}

	return *str1 - *str2;
}
