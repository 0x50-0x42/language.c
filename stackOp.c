#include<stdio.h>
#include<float.h>

#define MAX 100


float stack[MAX];
int top = -1;

void push(float val) {

	if(top == -1) {
		puts("stack is empty!");
		return;
	}

	if(top == MAX - 1 && stack[top] != 0.0f)
		puts("stack overflow!");

	stack[++top] = val;
}

float pop() {

	if(top == -1) {
		puts("stack is empty!");
		return FLT_MIN;
	}

	return stack[top--];
}

float peek() {

	if(top == -1) {
		puts("stack is empty!");
		return FLT_MIN;
	}

	return stack[top];
}
