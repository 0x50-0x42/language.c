#include<stdio.h>

void _itoa(int num, char str[]) {
	if(!num)
		return;

	_itoa(num / 10, str);
	printf("Hello");
	putchar((num % 10) + '0');
}
