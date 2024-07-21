/*
	K&R2 exercise 4.6:
	add commands for handling variables(it's easy to provide twenty-six variables
	with single-letter names);
	add a variable for the most recent printed value;
 */


#include<stdio.h>
#include<float.h>
#include<math.h>
#include<stdlib.h>

#define MAXLEN 1000
#define NUM '0'
#define SIN '!'
#define EXP '@'
#define POW '#'

#define PI 3.14
#define STRT_ANG 180

void push(double);
double pop(void);
double peek(void);
double duplicate(void);
double swap(void);
void clear(void);

int sign = 1;

int get_op(char[]);

int main(void) {

	int type;

	char rpn[MAXLEN];

	double op, val;

	printf("enter a postfix notation: ");

	while((type = get_op(rpn)) != EOF) {

		switch(type) {

			case SIN:
				push(sin(pop() * PI / STRT_ANG));
				break;

			case EXP:
				break;

			case POW:
				break;

			case 't': case 'T':
				if((val = peek()) == DBL_MIN) {
					puts("aborting!");
					break;
				}
				
				printf("top: %lf\n", val);
				break;

			case 'd': case 'D':
				if((val = duplicate()) == DBL_MIN) {
					puts("aborting!");
					break;
				}

				break;

			case 's': case 'S':
				if((val = swap()) == DBL_MIN) {
					puts("aborting!");
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
		}
	}

	printf("Result: %.3f\n", peek());

	return 0;
}
