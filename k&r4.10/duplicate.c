#include<stdio.h>
#include<float.h>

#define MAX 100

extern int top;
extern double stack[];

double duplicate() {

	if(top == MAX) {
		puts("duplication failed!");
		return DBL_MIN;
	}

	stack[top] = stack[top - 1];
	top++;

	return DBL_MAX;
}
