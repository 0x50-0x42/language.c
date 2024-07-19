#include<stdio.h>
#include<float.h>

extern int top;
extern double stack[];

double pop() {
	if(top == -1) {
		puts("stack overflow!");
		return DBL_MIN;
	}

	return stack[--top];
}
