#include<stdio.h>
#include "def.h"

int main(void) {
	char s[SIZE], t[SIZE];

	int n, len1, len2;

	printf("enter first string: ");
	len1 = _getline(s, SIZE);

	clearerr(stdin);

	printf("enter second string: ");
	len2 = _getline(t, SIZE);

	clearerr(stdin);

	printf("how many characters from first string to compare?: ");
	scanf("%d", &n);

	if(len1 - len2 < 0) {
		if(n > len1)
			n = len1;
		else if(n > len2)
			n = len1;
	}

	else {
		if(n > len2)
			n = len2;
		else if(n > len1)
			n = len2;
	}

	if(_strncmp(s, t, n) == 0)
		printf("The first %d characters of both the strings are equal!\n", n);

	else
		printf("The first %d characters of both the strings aren't equal!\n", n);

	return 0;
}
