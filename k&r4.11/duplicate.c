#include<stdio.h>
#include<float.h>

#define MAX 100

extern int top;

extern double stack[];

double duplicate() {

	if(top >= MAX) {
		puts("stack overflow!");
		return DBL_MIN;
	}

	if(top <= 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	stack[top] = stack[top - 1];
	top++;

	return DBL_MAX;
}
