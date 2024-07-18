#include<stdio.h>
#include<float.h>

#define MAX 100


double stack[MAX];
int top = -1;

void push(double val) {

	if(top == MAX - 1 && stack[top] != 0.0f) {
		puts("stack overflow!");
		return;
	}

	stack[++top] = val;
}

double pop() {

	if(top == -1) {
		puts("stack is empty!");
		return DBL_MIN;
	}

	return stack[top--];
}

double peek() {

	if(top == -1) {
		puts("stack is empty!");
		return DBL_MIN;
	}

	return stack[top];
}

double duplicate() {
	if(top == -1)
		return DBL_MIN;
	double val = stack[top];
	stack[++top] = val; // duplicating the top element
	return DBL_MAX;
}

double swap() {

	if(top <= 0)
		return DBL_MIN;

	double temp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = temp;

	return DBL_MAX;
}

void clear() {
	top = -1;
}
