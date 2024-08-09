#include<stdio.h>
#include<float.h>

#define MAX 100

extern int top;

extern double stack[];

double pop() {
	if(top < 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	return stack[--top];
}
