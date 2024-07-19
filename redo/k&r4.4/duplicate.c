#include<stdio.h>
#include<float.h>

#define MAX 100

extern double stack[];
extern int top;

double duplicate() {
	if(top == -1) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	if(top == MAX) {
		puts("stack overflow!");
		return DBL_MIN;
	}

	stack[top] = stack[top - 1];
	top++;

	return DBL_MAX;
}
