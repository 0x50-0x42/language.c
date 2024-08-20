#include<stdio.h>
#include "def.h"

int main(void) {

	char s[SIZE], t[SIZE];
	int n, len;

	printf("enter a string: ");
	len = _getline(t, SIZE);

	clearerr(stdin);

	printf("how many characters to copy to another string? ");
	scanf("%d", &n);

	n = n > len ? len : n;

	_strncpy(s, t, n);

	printf("Copied string: %s\n", s);

	return 0;
}
