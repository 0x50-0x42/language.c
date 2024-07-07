#include<stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
	if(top == MAX - 1 && stack[top] != 0) {
		puts("Overflow!");
			return;
	}

	stack[++top] = val;
}

int pop() {
	if(top < 0) {
		puts("Underflow!");
		return EOF;
	}

	return stack[top--];
}

int getop() {
	return stack[top];
}
