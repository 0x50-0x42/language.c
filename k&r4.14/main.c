/*
   K&R2 exercise 4.14
 */
#include<stdio.h>

#define swap(t, x, y) \
	t temp = x;\
	x = y;\
	y = temp;

int main(void) {

	int a = 10, b = 20;

	printf("a = %d, b = %d\n", a, b);

	{
		swap(int, a, b);

		/* this is replaced as:

		   int temp = x;
		   x = y;
		   y = temp;

		 */
	}

	printf("a = %d, b = %d\n", a, b);

	return 0;
}
