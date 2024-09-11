#include<stdio.h>
#include<float.h>

#define MAX 1000

static double stack[MAX];

static int top = -1;


void push(double val) {
	if(top == MAX - 1) {
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
	return stack[top];
}
