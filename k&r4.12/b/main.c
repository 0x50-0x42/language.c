/*
   K&R2 exercise 4.12
*/

#include<stdio.h>
#include<string.h>
#include "conv.h"

int main(void) {

	char numStr[MAXLEN];

	int num;

	printf("enter a number: ");
	scanf("%d", &num);

	_itoa(num, numStr, 0);

	reverse(numStr);

	printf("String: %s\n", numStr);

	return 0;
}
