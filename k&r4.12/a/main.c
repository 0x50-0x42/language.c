/*
   K&R2 exercise 4.12
*/

#include<stdio.h>

void _itoa(int);

int main(void) {
	int num;

	printf("enter a number: ");
	scanf("%d", &num);

	printf("%d converted to string: ", num);

	_itoa(num);
	printf("\n");

	return 0;
}
