#include<stdio.h>
#include<float.h>

#define STKSZ 1000

static double stack[STKSZ];
static int top = -1;

void push(double val) {
	if(top == STKSZ - 1) {
		puts("stack overflow!");
		return;
	}

	stack[++top] = val;
}

double pop() {
	if(top < 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	return stack[top--];
}

double peek() {
	if(top < 0) {
		puts("stack is emtpy!");
		return DBL_MIN;
	}

	return stack[top];
}
