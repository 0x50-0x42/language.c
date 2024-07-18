#include<stdio.h>

#define MAX 100

double stack[MAX];

int top = 0;

void push(double val) {
	if(top == MAX) {
		puts("stack overflow!");
		return;
	}

	stack[top++] = val;
}
