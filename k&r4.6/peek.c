#include<stdio.h>
#include<float.h>

extern double stack[];
extern int top;

double peek() {

	if(top < 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	return stack[top - 1];
}
