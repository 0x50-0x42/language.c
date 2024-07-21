#include<float.h>
#include<stdio.h>

#define MAX 100

extern double stack[];
extern int top;

double duplicate(void) {
	if(top < 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	if(top >= MAX) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	stack[top] = stack[top - 1];
	top++;

	return DBL_MAX;
}
