/*
	K&R2 exercise 4.5
*/


#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include<math.h>

#define MAXLEN 1000
#define NUM '!'
#define SIN '@'
#define EXP '#'

#define PI 3.14
#define STR_ANG 180.0

int sign = 1;

void push(double);
double pop(void);
double peek(void);
double duplicate(void);
double swap(void);
void clear(void);
int get_op(char[]);

int main(void) {

	char rpn[MAXLEN];

	int type;

	double op, val;

	printf("enter a reverse polish notation: ");

	while((type = get_op(rpn)) != EOF) {

		switch(type) {

			case SIN:
				push(sin(pop() * PI / STR_ANG));
				break;

			case EXP:
				push(exp(pop()));
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

			case NUM:
				push(sign * atof(rpn));
				sign = 1;
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

			case '^':
				op = pop();
				push(pow(pop(),op));
				break;
		}
	}

	printf("Result: %.3lf\n", peek());
	return 0;
}
