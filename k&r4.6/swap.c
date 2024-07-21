#include<float.h>
#include<stdio.h>

extern double stack[];
extern int top;

double swap(void) {
	if(top < 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	double temp = stack[top - 1];
	stack[top - 1] = stack[top - 2];
	stack[top - 2] = temp;

	return DBL_MAX;
}
