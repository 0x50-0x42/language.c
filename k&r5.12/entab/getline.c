#include<stdio.h>

int _getline(char *str, int lim) {
	int c;

	char *base = str;

	while((c = getchar()) != EOF && (str - base) < lim - 1)
		*str++ = c;
	str--;
	
	while(*str == ' ' || *str == '\n' || *str == '\t')
		str--;

	*++str = '\0';

	return (str - base);
}
