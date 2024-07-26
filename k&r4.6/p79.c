/*
	K&R2 exercise 4.6:
	add commands for handling variables(it's easy to provide twenty-six variables
	with single-letter names);
	add a variable for the most recent printed value;
 */

// uppercase letters are variables


#include<stdio.h>
#include<float.h>
#include<math.h>
#include<stdlib.h>

#define MAXLEN 1000
#define NUM '0'
#define SIN '!'
#define EXP '@'
#define POW '#'
#define VAR '&'

#define PI 3.14
#define STRT_ANG 180

void push(double);
double pop(void);
double peek(void);
double duplicate(void);
double swap(void);
void clear(void);

int sign = 1, variable;
double vars[26];

int get_op(char[]);

int main(void) {

	int type;

	char rpn[MAXLEN];

	double op, val;

	printf("enter a postfix notation: ");

	while((type = get_op(rpn)) != EOF) {

		switch(type) {

			case SIN:
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push(sin(vars[(int)val - 'A'] * PI / STRT_ANG));
				else
					push(sin(pop() * PI / STRT_ANG));
				break;

			case EXP:
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push(exp(vars[(int)val - 'A']));
				else
					push(exp(val));
				break;

			case POW:
				op = pop();
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push(pow(vars[(int)val - 'A'], op));
				else
					push(pow(val, op));
				break;

			case 't': case 'T':
				if((val = peek()) == DBL_MIN) {
					puts("aborting!");
					break;
				}

				if((int)val >= 'A' && (int)val <= 'Z')
					printf("top: %lf\n", vars[(int)val - 'A']);
				else
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

			case VAR:
				push(variable);
				break;
				
			case '+':
				op = pop();
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push(vars[(int)val - 'A'] + op);
				else
					push(val + op);
				break;

			case '-':
				op = pop();
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push(vars[(int)val - 'A'] - op);
				else
					push(val - op);
				break;

			case '*':
				op = pop();
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push(vars[(int)val - 'A'] * op);
				else
					push(val * op);
				break;

			case '/':
				op = pop();
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push(vars[(int)val - 'A'] / op);

				else
					push(val / op);
				break;

			case '%':
				op = pop();
				val = pop();
				if((int)val >= 'A' && (int)val <= 'Z')
					push((int)vars[(int)val - 'A'] % (int)op);
				else
					push((int)val % (int)op);
				break;

			case '=':
				op = pop();
				val = pop();
				vars[(int)val - 'A'] = op;
				push(val);
				break;
		}
	}

	if((int)(val = peek()) >= 'A' && (int)val <= 'Z')
		printf("%.3lf\n", vars[(int)val - 'A']);

	else
		printf("Result: %.3lf\n", val);

	return 0;
}
