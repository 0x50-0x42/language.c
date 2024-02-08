// In original C, this was how functions were declared and defined !!

#include<stdio.h>

int power();

int main(void) {
	printf("2^5 = %d\n", power(2, 5));
	return 0;
}

int power(base, n)
	int base, n; {
		int prod=1;
		for(int i=0; i<n; i++)
			prod*=base;

		return prod;
	}

