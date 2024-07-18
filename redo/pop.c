#include<stdio.h>
#include<float.h>

extern double stack[];
extern int top;

double pop() {
	if(top == -1) {
		puts("stack is empty!");
		return DBL_MIN;
	}

	return stack[--top];
}
