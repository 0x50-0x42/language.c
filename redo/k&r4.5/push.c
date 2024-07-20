#include<stdio.h>

#define MAX 100

double stack[MAX];
int top;

void push(double val) {
	if(top == MAX) {
		puts("stack overflow!");
		return;
	}

	stack[top++] = val;
}
