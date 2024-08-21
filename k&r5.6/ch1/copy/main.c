#include<stdio.h>
#include "def.h"

int main(void) {

	char s[SIZE], t[SIZE];

	printf("enter a string: ");
	int len = _getline(s, SIZE);

	copy(t, s); // copy s to t

	printf("copied string: %s\n", t);

	return 0;
}
