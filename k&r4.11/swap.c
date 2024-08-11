#include<stdio.h>
#include<float.h>

extern int top;

extern double stack[];

double swap() {

	if(top <= 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	double temp = stack[top - 1];
	stack[top - 1] = stack[top - 2];
	stack[top - 2] = temp;

	return DBL_MAX;
}
