/*
   K&R2 exercise 4.10
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

#define MAXLEN 1000
#define NUM '0'
#define SIN '$'
#define COS '!'
#define EXP '#'
#define VAR '@'
#define PI 3.14
#define STRT_ANGL 180.0
#define INV '~'

void push(double);
double pop(void);
double peek(void);
double duplicate(void);
double swap(void);
void clear(void);
int getLine(char[], int); // get an entire line of input
int parse(char[], char[], int); // parse the input

int i, sign = 1, var = '\0';

double variable[26];

int main(void) {

	char rpn[MAXLEN];
	char operand[MAXLEN];

	int type;

	double op1 = 0.0, op2 = 0.0, val = 0.0;

	printf("enter a postfix expression: ");

	int len = getLine(rpn, MAXLEN);

	while((type = parse(rpn, operand, len)) != EOF) {

		switch(type) {

			case 's': case 'S': // swap
				if((val = swap()) == DBL_MAX)
					puts("swap successful!");
				break;

			case 'd': case 'D': // duplicate
				if((val = duplicate()) == DBL_MAX)
					puts("duplication successful!");
				break;

			case 't': case 'T': // view top
				if((val = peek()) != DBL_MAX)
					printf("top: %lf\n", val);
				break;

			case 'c': case 'C':
				clear();
				break;

			case SIN:
				op1 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z')
					push(sin(variable[(int)op1 - 'A'] * PI / STRT_ANGL));
				else
					push(sin(op1 * PI / STRT_ANGL));

				break;

			case COS:
				op1 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z')
					push(cos(variable[(int)op1 - 'A'] * PI / STRT_ANGL));
				else
					push(cos(op1 * PI / STRT_ANGL));

				break;

			case EXP:
				op1 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z')
					push(exp(variable[(int)op1 - 'A']));
				else
					push(exp(op1));

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
				op1 = pop();
				op2 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z') {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push(variable[(int)op1 - 'A'] * variable[(int)op2 - 'A']);
					else
						push(variable[(int)op1 - 'A'] * op2);

				}

				else {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push(op1 * variable[(int)op2 - 'A']);
					else
						push(op1 * op2);
				}

				break;

			case '%':
				op1 = pop();
				op2 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z') {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push((int)variable[(int)op2 - 'A'] % (int)variable[(int)op1 - 'A']);
					else
						push((int)op2 % (int)variable[(int)op1 - 'A']);
				}

				else {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push((int)variable[(int)op2 - 'A'] % (int)op1);
					else
						push((int)op2 % (int)op1);
				}

				break;

			case '/':
				op1 = pop();
				op2 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z') {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push(variable[(int)op2 - 'A'] / variable[(int)op1 - 'A']);
					else
						push(op2 / variable[(int)op1 - 'A']);
				}

				else {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push(variable[(int)op2 - 'A'] / op1);
					else
						push(op2 / op1);
				}

				break;

			case '^':
				op1 = pop();
				op2 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z') {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push(pow(variable[(int)op2 - 'A'], variable[(int)op1 - 'A']));
					else
						push(pow(op2, variable[(int)op1 - 'A']));
				}

				else {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push(pow(variable[(int)op2 - 'A'], op1));
					else
						push(pow(op2, op1));
				}

				break;

			case '=': // for variables
				op1 = pop();
				op2 = pop();

				if(op1 >= 'A' && (int)op1 <= 'Z')
					variable[(int)op2 - 'A'] = variable[(int)op1 - 'A'];
				else
					variable[(int)op2 - 'A'] = op1;

				push(op2);

				break;

			case VAR:
				push(var);
				break;

			default: // something invalid
				break;
		}
	}

	val = peek();

	if((int)val >= 'A' && (int)val <= 'Z')
		printf("Result: %.3lf\n", variable[(int)val - 'A']);
	else
		printf("Result: %.3lf\n", val);

	return 0;
}
