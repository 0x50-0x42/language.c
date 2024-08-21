#include<stdio.h>
#include "def.h"

int main(void) {

	char s[SIZE];

	printf("enter a string: ");
	int len = _getline(s, SIZE);

	reverse(s, len);
	
	printf("Reversed string: %s\n", s);

	return 0;
}
