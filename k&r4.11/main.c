/*
   K&R2 exercise 4.11
*/



#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include "calc.h"

int sign = 1, var;

double variable[26];

int main(void) {

	char operand[MAXLEN];

	double op1, op2, val;

	printf("enter reverse Polish notation: ");

	int type;

	while((type = get_op(operand)) != EOF) {
		switch(type) {
			case NUM:
				push(sign * atof(operand));
				sign = 1;
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
				
			case VAR:
				push(var);
				break;

			case 's':
				if((val = swap()) == DBL_MAX)
					;
				break;

			case 'd':
				if((val = duplicate()) == DBL_MAX)
					;
				break;

			case 't':
				if((val = peek()) != DBL_MIN)
					printf("top: %lf\n", val);
				break;

			case 'c':
				clear();
				break;


			case '+':
				op1 = pop();
				op2 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z') {
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
						push(variable[(int)op2 - 'A'] * variable[(int)op1 - 'A']);
					else
						push(variable[(int)op1 - 'A'] * op2);
				}

				else {
					if((int)op2 >= 'A' && (int)op2 <= 'Z')
						push(variable[(int)op2 - 'A'] * op1);
					else
						push(op2 * op1);
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

			case '=':
				op1 = pop();
				op2 = pop();

				if((int)op1 >= 'A' && (int)op1 <= 'Z')
					variable[(int)op2 - 'A'] = variable[(int)op1 - 'A'];
				else
					variable[(int)op2 - 'A'] = op1;

				push(op2);
				break;

			default: // invalid
				break;
		}
	}

	if((int)(val = peek()) >= 'A' && (int)val <= 'Z')
		printf("Result: %.3lf\n", variable[(int)val - 'A']);
	else
		printf("Result: %.3lf\n", val);

	return 0;
}
