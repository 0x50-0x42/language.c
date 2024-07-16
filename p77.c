/*
	K&R2 exercise 4.4: continuation of K&R2 exercise 4.3

		add commands to print the top element of the stack without
		popping, to duplicate it, and to swap the top two elements;
		add a command to clear the stack;
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLEN 1000

void _getline(char[], int);
void push(float);
float pop();
float peek();

int main(void) {
	
	char rpn[MAXLEN], cmd;

	float op1, op2;

	int sign = 1;

	// take reverse polish notation as input
	printf("enter a reverse polish notation: ");
	_getline(rpn, MAXLEN);

	// begin evaluation
	for(int i = 0; rpn[i] != '\0'; i++) {

		printf("> ");
		scanf(" %c", &cmd);

		switch(rpn[i]) {

			case '+':
				push(pop() + pop());

				break;

			case '-':
				if(rpn[i + 1] != '\0') {
					if(rpn[i + 1] != ' ') {
						sign = -1;
						break;
					}
				}

				op1 = pop();
				op2 = pop();

				push(op2 - op1);

				break;

			case '*':

				push(pop() * pop());

				break;
				
			case '/':

				op1 = pop();
				op2 = pop();

				push(op2 / op1);

				break;

			case '%':

				op1 = pop();
				op2 = pop();

				push((int)op2 % (int)op1);

				break;

			default:
				// check if there is a floating point number or negative number
				if(isdigit(rpn[i])) { // check whether rpn[i] is a digit
					int idx = 0;
					char dig[MAXLEN / 10];
					while(rpn[i] != ' ' && rpn[i] != '\0' && isdigit(rpn[i]))
						dig[idx++] = rpn[i++];
					if(rpn[i] == '.') { // number is a floating-point number
						dig[idx++] = rpn[i++];
						while(rpn[i] != ' ' && rpn[i] != '\0' && isdigit(rpn[i]))
							dig[idx++] = rpn[i++];
					}

					i--;

					dig[idx] = '\0';

					push(sign * atof(dig));
					sign = 1;
				}

				break;

		}
	}

	printf("Result: %.3f\n", peek());

	return 0;
}
