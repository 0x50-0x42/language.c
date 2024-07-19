/*
   redoing K&R2 exercise 4.3
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXLEN 1000
#define NUM '0'

double pop();
void push(double);
double peek();
char get_op(char[]);

int sign = 1;


int main(void) {

	char rpn[MAXLEN];

	double op1;

	char type;

	puts("enter a reverse Polish notation: ");

	while((type = get_op(rpn)) != EOF) {
		switch(type) {
			case NUM:
				push(sign * atof(rpn));
				sign = 1;
				break;

			case '+':
				push(pop() + pop());
				break;

			case '-':
				op1 = pop();
				push(pop() - op1);
				break;

			case '/':
				op1 = pop();
				push(pop() / op1);
				break;

			case '*':
				push(pop() * pop());
				break;

			case '%':
				op1 = pop();
				push((int)pop() % (int)op1);
				break;
		}
	}

	printf("Result: %.3f\n", peek());

	return 0;
}
