#include<stdio.h>
#include "def.h"

int main(void) {

	char string[SIZE];

	int num = 569012;

	itoa(num, string);

	printf("String: %s\n", string);

	return 0;
}
