/*
	Redoing K&R2 exercise 4.4
*/

#include<stdio.h>
#include<float.h>
#include<stdlib.h>

#define MAXLEN 1000
#define NUM '0'

void push(double);
double pop();
double peek();
double duplicate(); // duplicate the top element
double swap(); // swap the top two elements
void clear(); // clear the stack
int get_op(char[]);

int sign = 1;

int main(void) {

	char rpn[MAXLEN];

	double op, val;

	int type;

	while((type = get_op(rpn)) != EOF) {

		switch(type) {
			case NUM:
				push(sign * atof(rpn));
				sign = 1;
				break;

			case 't': case 'T':
				if((val = peek()) == DBL_MIN) {
					puts("aborted!");
					break;
				}

				printf("top: %lf\n", val);

				break;

			case 'd': case 'D':
				if((val = duplicate()) == DBL_MIN) {
					puts("aborted!");
					break;
				}

				break;

			case 's': case 'S':
				if((val = swap()) == DBL_MIN) {
					puts("aborted!");
					break;
				}

				break;

			case 'c': case 'C':
				clear();

				break;

			case '+':
				push(pop() + pop());
				break;

			case '-':
				op = pop();
				push(pop() - op);
				break;
				
			case '*':
				push(pop() * pop());
				break;

			case '/':
				op = pop();
				push(pop() / op);
				break;

			case '%':
				op = pop();
				push((int)pop() % (int)op);
				break;
		}
	}

	printf("Result: %.3lf\n", peek());

	return 0;
}
