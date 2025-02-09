#include<stdio.h>
#include<float.h>


#define MAXSZ 1000

static double stack[MAXSZ];
static int top = -1;

void push(double val) {
	if(top == MAXSZ - 1) {
		puts("----Overflow----");
		return;
	}

	stack[++top] = val;
}

double pop() {
	if(top < 0) {
		puts("----Underflow----");
		return DBL_MAX;
	}

	return stack[top--];
}

double peek() {
	if(top < 0)
		return DBL_MAX;

	return stack[top];
}
