/*
   K&R2 exercise 4.10
*/

#include<stdio.h>
#include<stdlib.h>
#include<float.h>

#define MAXLEN 1000
#define NUM '0'
#define SIN '$'
#define EXP '#'

void push(double);
double pop(void);
double peek(void);
double duplicate(void);
double swap(void);
void clear(void);
int getLine(char[], int); // get an entire line of input
int parse(char[], int); // parse the input

int i, sign = 1;

double variable[26];

int main(void) {

	char rpn[MAXLEN];
	char operand[MAXLEN];

	double op1 = 0.0l, op2 = 0.0l;

	printf("enter a postfix expression: ");

	printf("Expression: %s\n", rpn);

	int len = getLine(rpn, MAXLEN);

	while(parse(rpn, operand, len) != something) {

		case SIN:
			break;

		case EXP:
			break;

		case NUM:
			push(sign * atof(operand));
			sign = 1;
			break;

		case '+':
			op1 = pop();
			op2 = pop();

			if((int)op1 >= 'A' && (int)op1 <= 'Z') { // if op1 is one of the alphabets(in this case, we will call them variables)
				if((int)op2 >= 'A' && (int)op2 <= 'Z')
					push(variable[(int)op1 - 'A'] + variable[(int)op2 - 'A']);

				else
					push(variable[(int)op1 - 'A'] + op2);
			}

			else {
				if((int)op2 >= 'A' && (int)op2 <= 'Z')
					push(op1 + variable[(int)op2 - 'A']);
				else
					push(op1 + op2);
			}

			break;

		case '-':
			op1 = pop();
			op2 = pop();

			if((int)op1 >= 'A' && (int)op1 <= 'Z') {
				if((int)op2 >= 'A' && (int)op2 <= 'Z')
					push(variable[(int)op2 - 'A'] - variable[(int)op1 - 'A']);
				else
					push(op2 - variable[(int)op1 - 'A']);
			}
			
			else {
				if((int)op2 >= 'A' && (int)op2 <= 'Z')
					push(variable[(int)op2 - 'A'] - op1);
				else
					push(op2 - op1);
			}

			break;

		case '*':
			break;

		case '/':
			break;

		case '^':
			break;

		case '=': // for variables
			break;
	}

	return 0;
}
