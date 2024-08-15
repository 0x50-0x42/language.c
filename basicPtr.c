#include<stdio.h>

int main(void) {

	int x = 10;

	int *ip;
	ip = &x;

	printf("x = %d\n", *ip);

	++*ip;

	printf("x = %d\n", *ip);

	(*ip)++;

	printf("x = %d\n", *ip);

	return 0;
}
