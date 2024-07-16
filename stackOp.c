#include<stdio.h>
#include<float.h>

#define MAX 100


float stack[MAX];
int top = -1;

void push(float val) {

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

float duplicate() {
	if(top == -1)
		return FLT_MIN;
	float val = stack[top];
	stack[++top] = val; // duplicating the top element
	return FLT_MAX;
}

float swap() {

	if(top <= 0)
		return FLT_MIN;

	float temp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = temp;

	return FLT_MAX;
}

void clear() {
	top = -1;
}
