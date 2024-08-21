#include<stdio.h>
#include "def.h"

int main(void) {

	char s[SIZE];


	puts("enter a string:");
	while(_getline(s, SIZE) != EOF)
		printf("%s\n", s);

	return 0;
}
