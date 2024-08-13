#include<stdio.h>

void _itoa(int num) {
	if(!num)
		return;

	if(num < 0) { // negative number
		putchar('-');
		num *= -1; // make it positive
	}

	_itoa(num / 10);
	putchar((num % 10) + '0');
}
