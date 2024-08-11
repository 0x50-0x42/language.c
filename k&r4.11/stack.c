#include<stdio.h>
#include<float.h>

#define MAX 100

int top;

double stack[MAX];

void push(double val) {
	if(top == MAX) {
		puts("stack overflow!");
		return;
	}

	stack[top++] = val;
}


double pop() {
	if(top <= 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	return stack[--top];
}

double peek() {
	if(top <= 0) {
		puts("stack underflow!");
		return DBL_MIN;
	}

	return stack[top - 1];
}
