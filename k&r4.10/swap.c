#include<stdio.h>
#include<float.h>

#define MAX 100

extern int top;
extern double stack[];

double swap() {

	if(top < 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	if(top <= 1) {
		puts("failed to swap!");
		return DBL_MIN;
	}

	int temp = stack[top - 1];
	stack[top - 1] = stack[top - 2];
	stack[top - 2] = temp;

	return DBL_MAX;
}
