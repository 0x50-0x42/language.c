#include<stdio.h>
#include "def.h"

int main(void) {

	char s[SIZE], t[SIZE];

	int n, len;

	printf("enter first string: ");
	_getline(s, SIZE);

	clearerr(stdin);

	printf("enter second string: ");
	len = _getline(t, SIZE);

	clearerr(stdin);

	printf("how many characters should be concatenated to the first string?: ");
	scanf("%d", &n);

	n = n > len ? len : n;

	_strncat(s, t, n);

	printf("Concatenated string: %s\n", s);

	return 0;
}
