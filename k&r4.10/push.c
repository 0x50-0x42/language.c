#include<stdio.h>

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
