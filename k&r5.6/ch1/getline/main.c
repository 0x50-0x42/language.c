#include<stdio.h>
#include "def.h"

int main(void) {

	char str[SIZE];

	printf("enter a string: ");

	int len = _getline(str, SIZE);

	printf("String: %s\n", str);

	return 0;
}
