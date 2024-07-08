/*
	K&R2 example:
		evaluation of reverse polish notations
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

void _getline(char[], int);
void push(int);
int pop();
int getTop();

int main(void) {

	char reversePolish[MAXLEN];

	int op1, op2;

	printf("enter a reverse polish notation: ");
	_getline(reversePolish, MAXLEN);

	for(int i = 0; reversePolish[i] != '\0'; i++) {

		switch(reversePolish[i]) {
			case '+':
				op1 = pop();
				op2 = pop();

				push(op1 + op2);

				break;
			case '-':

				op1 = pop();
				op2 = pop();

				push(op2 - op1);

				break;
			case '*':
				op1 = pop();
				op2 = pop();

				push(op1 * op2);

				break;
			case '/':
				op1 = pop();
				op2 = pop();

				push(op2 / op1);

				break;
			default:
				push(reversePolish[i] - '0');
				break;
		}
	}

	printf("Value: %d\n", getTop());
	return 0;
}
