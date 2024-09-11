// just implementing the rudimentary calculator using pointer

#include<stdio.h>
#include<stdlib.h>

#include "def.h"
#include "stack.h"

#define NUM '0'

int main(void) {

	char operand[SIZE];

	puts("enter some expression:");

	int type;

	double val;

	while((type = getop(operand)) != EOF) {

		switch(type) {
			case NUM:
				push(atof(operand));
				break;

			case '+':
				push(pop() + pop());
				break;

			case '-':
				val = pop();
				push(pop() - val);
				break;

			case '*':
				push(pop() * pop());
				break;

			case '/':
				val = pop();
				push(pop() / val);
				break;

			case '%':
				val = pop();
				push((int)pop() % (int)val);
				break;
		}
	}

	printf("value: %.3f\n", peek());

	return 0;
}
